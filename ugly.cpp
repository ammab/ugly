#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
void asc (string);
int power(int,int);
void add(int, int *,int d[],char,int);
int main(int arg,char* argv[]) 
{
	   string  line ;
	   stringstream ss;
	   ifstream myfile (argv[1]);
	   strcpy((char *)&line,"");
	  if (myfile.is_open())
	  {
	 while(myfile.get() != EOF)
	 {
		myfile.unget();
		while(getline(myfile,line))
		{
		 if(line[0]  != 0 )
	     {
	    	asc(line);
	        cout << endl;
	      }
	      else cout <<  "1" << endl;
		}
	 }
       myfile.close();
	  }
	  else cout << "Unable to open file";
	 	return 0;
}

void asc(string ln)
{
   int cnt =0,k=0,a=0,sum1 =0;
   int l=0,m=0,i=1,n=0,len=0,j=0,y=0;
   stringstream ss;
   char s[1];
   len = ln.length();
   k = power(3,len-1)-1;
   int num[len],num1=0;
   signed int sum[k] ;
     for(a=0;a<=k;a++)
          sum[a]= 0;
     for(l=0;l<len;l++)
     {
        num[l]=0;
        s[0] = ln[l];
        ss.clear();
        ss.str(&s[0]);
        ss>>num[l];
        ss.clear();
       num[l] = abs(num[l]);
     }
      ss.clear();
      ss.str(&ln[0]);
      ss>>num1;
      ss.clear();
      num1 = abs(num1);
      y=power(2,(len-1));
      m=0;j=0;
       for(l=0;l<len;l++)
      {
    	    i=0;
    	    if(l==0)
    	    {
    	     	sum[i]=sum[i+1]=num[0];
    	     	i=i+2;
    	    }
    	    for(m=0;(m<j) && (l>0);m++)
    	    {
    	    	 add(num[l],&m,&sum[0],'+',y);
    	    	 m--;
    	    }
    	     for(cnt=m;(cnt>0) &&(m<y);cnt=cnt-2)
    	    {
    	    	   j=cnt*2-2;
    	    	   sum[j]=sum[j+1]=sum[cnt-1];
    	    	   sum[j-1]=sum[j-2]=sum[cnt-2];
    	     }
    	    if(l!=0)
    	    	j=m*2;
    	    else j =i;
    	   if(len!=1) i=m;
    	   else i=1;
       }
      for(l=1;(l<len) &&(i<k);l++)
      {
    	  sum1 =  num1/power(10,l);
    	  sum[i+1]= sum[i]=sum1;
    	  for(cnt=1;sum1/10!=0;cnt++)sum1=sum1/10;
    	  sum1 = sum[i+1]= sum[i];
    	  a  =  num1%power(10,l);
    	 add(a,&i,&sum[0],'+',k);
 	     for(n=1; (i<k)&&(n < cnt) ;n++)
         {
 	    	     sum[i+1]=sum[i]=sum1/power(10,n);
        		 m=i;
         		 add(sum1%power(10,n),&i,&sum[0],'+',k);
        		 i=m;
        		 add(a,&i,&sum[0],'+',k);
        		  sum[i+1]=sum[i]=sum1/power(10,n);
        		  m=i;
        		  add(sum1%power(10,n),&i,&sum[0],'-',k);
        		  i=m;
        		  add(a,&i,&sum[0],'+',k);
        		  if((len >4)&& (n>1))
        		  {
        			  j=0;
        			  for(m=0;m<2;m++)
        				  sum[i+m]=sum1/power(10,n);
        		   for(y=len-n;((y<len-1) &&  (a!=(num[len-2]*10+num[len-1])));y++)
        			     j=j*10+num[y];
        		   if(a==(num[len-2]*10+num[len-1]))
        		   		   j=num[len-3];
        		   	      m=i;
        		   	      int x,z;
        		     add((sum1%power(10,n))/power(10,n-1),&i,&sum[0],'+',k);
        		     for(x=m+1,z=i;x>=m;x--,z=z-2)
        		    	 sum[z]=sum[z+1]=sum[x];
        		     for(x=m;x<i+1;)
        		     {
        		       for(z=0;z<2;z++)
        		        add(j,&x,&sum[0],'+',k);
        		     }
        		     z=x+2;
        		     for(x;(x>m) &&(x<k);x--,z=z-2)
        		           sum[z]=sum[z+1]=sum[x-1];
        		     for(i=m;i<m+8;)
        		     {
        		    	 for(z=0;z<2;z++)
        		            add(a,&i,&sum[0],'+',k);
        		     }
        		     if(a==(num[len-2]*10+num[len-1]))
        		     {
        		    	  j=a/10;
        		    	  a=a%10;
        		    	  for(m=0;m<2;m++)
        		    	    sum[i+m]=sum1/power(10,n);
        		    	  m=i;
        		    	  add((sum1%power(10,n)),&i,&sum[0],'+',k);
        		    	  for(x=m+1,z=i;x>=m;x--,z=z-2)
        		             sum[z]=sum[z+1]=sum[x];
        		    	  for(x=m;x<i+1;)
        		    	  {
        		    		  for(z=0;z<2;z++)
        		    		      add(j,&x,&sum[0],'+',k);
        		    	   }
        		    	   z=x+2;
        		    	   for(x;(x>m) &&(x<k);x--,z=z-2)
        		             sum[z]=sum[z+1]=sum[x-1];
        		    	    for(i=m;i<m+8;)
        		    	    {
        		    	    	for(z=0;z<2;z++)
        		    	          add(a,&i,&sum[0],'+',k);
        		    	     }
        		     }
         }
     }
     cnt=0;
  }
      cnt=0;
    for( m =0;m<i;m++)
      if((abs(sum[m]) % 2 ==0) || abs((sum[m]) % 3 == 0) || (abs(sum[m]) % 5 ==0) || (abs(sum[m])  %7 ==0)) cnt++;
       cout << cnt;
  return;  
}


int power (int c, int d)
{
	int e,ans=1;
	for (e =0;e<d;e++)
		ans = c*ans;
	return ans;
}

void add(int x, int *y,int d[],char c,int z)
{
	switch(c)
	{

	case '+':
	 if(*y<z) { d[*y]=d[*y]+x;*y=*y+1;}
	 if(*y<z) {d[*y]= d[*y]-x;*y=*y+1;}
	 break;

	case '-':
		if(*y<z)	{ d[*y]=d[*y]-x;*y=*y+1;}
		if(*y<z) { d[*y]= d[*y]+x;*y=*y+1;}
		 break;
	default:
		break;

	}
	return;
}
