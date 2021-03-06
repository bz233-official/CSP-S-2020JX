#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long r;
int q;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int day,month,year;
		scanf("%lld",&r);
		if(r==0)
		{
			cout<<"1 1 4713 BC"<<endl;
			continue;
		}
		if((r>=1)&&(r<=1721423))
		{
			for(year=4713;year>1;year--)
			{
				if((r<365)||((r==365)&&((year-1)%4==0)))
				{
					break;
				}
				r-=365;
				if((year-1)%4==0)
				{
					r--;
				}
			}
			for(month=1;month<=12;month++)
			{
				for(day=1;r>0;day++)
				{
					if((day==30)&&((month==4)||(month==6)||(month==9)||(month==11)))
					{
						r--;
						break;
					}
					if((day==28)&&(month==2)&&((year-1)%4!=0))
					{
						r--;
						break;
					}
					if((day==29)&&((year-1)%4==0)&&(month==2))
					{
						r--;
						break;
					}
					r--;
					if(day==31)
					{
						break;
					}
				}
				if(r==0)
				{
					break;
				}
			}
			cout<<day<<" "<<month<<" "<<year<<" BC"<<endl;
		}
		if((r>=1721424)&&(r<=2299160))
		{
			r-=1721424;
			for(year=1;year<1582;year++)
			{
				if((r<365)||((r==365)&&(year%4==0)))
				{
					break;
				}
				r-=365;
				if(year%4==0)
				{
					r--;
				}
			}
			for(month=1;month<=12;month++)
			{
				for(day=1;r>0;day++)
				{
					if((day==30)&&((month==4)||(month==6)||(month==9)||(month==11)))
					{
						r--;
						break;
					}
					if((day==28)&&(month==2)&&(year%4!=0))
					{
						r--;
						break;
					}
					if((day==29)&&(year%4==0)&&(month==2))
					{
						r--;
						break;
					}
					r--;
					if(day==31)
					{
						break;
					}
				}
				if(r==0)
				{
					break;
				}
			}
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
		if(r>=2299161)
		{
			r-=2299161;
			if(r<=78)
			{
				year=1582;
				for(month=10;month<=12;month++)
				{
					if(month!=10)
					{
						for(day=1;r>0;day++)
						{
							if((day==30)&&(month==11))
							{
								r--;
								break;
							}
							r--;
							if(day==31)
							{
								break;
							}
						}
						if(r==0)
						{
							break;
						}
					}
					else
					{
						for(day=15;r>0;day++)
						{
							r--;
							if(day==31)
							{
								break;
							}
						}
						if(r==0)
						{
							break;
						}
					}
				}
			}
			else
			{
				r-=78;
				for(year=1583;;year++)
				{
					if((r<365)||((r==365)&&(year%4==0)&&(year%100!=0))||((r==365)&&(year%400==0)))
					{
						break;
					}
					r-=365;
					if(((year%4==0)&&(year%100!=0))||(year%400==0))
					{
						r--;
					}
				}
				for(month=1;month<=12;month++)
				{
					for(day=1;r>0;day++)
					{
						if((day==30)&&((month==4)||(month==6)||(month==9)||(month==11)))
						{
							r--;
							break;
						}
						if(((day==28)&&(month==2)&&(year%4!=0))||((day==28)&&(month==2)&&(year%100==0)&&(year%400!=0)))
						{
							r--;
							break;
						}
						if(((day==29)&&(year%4==0)&&(month==2))||((day==29)&&(year%400==0)&&(month==2)))
						{
							r--;
							break;
						}
						r--;
						if((day==31)&&((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)))
						{
							break;
						}
					}
					if(r==0)
					{
						break;
					}
				}
			}
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
	}
	return 0;
}