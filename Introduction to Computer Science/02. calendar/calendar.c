#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
#include <cstdlib>
#include <iostream>
#include <conio.h>
*/
/*萬年曆程式開始*/
int main(int argc, char *argv[])
{
  
  char str1[10],str2[10];
  long days,spaces,year1,year2;
  int key,delay,mind[41],x,i,j,t1,t2,cho,valstr1,valstr2,space1,firstday,long1,long2,month1,monthdays,fun=0,
      mask[14][37]={
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {0,0,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0},
    {1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,0,0},
    {0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1},
    {0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,1},
    {0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0},
    {0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,0},
    {1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0},
    {1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
    {1,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0}
                   };
/*印出本程式的標題*/
  for(i=0;i<=13;i++)
  {
    for(j=0;j<=36;j++)
    {
      if(mask[i][j]==1)
      {
        printf("☆"); 
      }
      else
      {
        printf("　");
      }
    }
    printf("\n");
  }
/*程式開始，用無限迴�等]住*/ 
  while(1)
  {
/*將各值清為零*/ 
    cho=0;
	for(i=0;i<=41;i++)
	{
      mind[i]=0;
      if(i<=10)
      {
        str1[i]=0;
        str2[i]=0; 
      } 
    }
/*顯示並輸入資料*/ 
    printf("\n---------------∮四電子一甲-★-B9502028-★-陳敬翔〈星晴小羽〉製∮---------------\n請輸入西元年份。\n"); 
    scanf("%s",&str1);
    printf("西元第%s年，讀取完畢！\n",str1); 
    printf("--------------------\n請輸入月份。\n");
    scanf("%s",&str2);
    printf("第%s月份，讀取完畢！\n--------------------\n",str2); 
    long1 = strlen(str1);
    long2 = strlen(str2);
/*將輸入的字串資料轉成整數（若輸入的值不為整數資料，可由下面的判斷過濾）*/
    x=1;
    valstr1=0; 
    for(t1=long1-1;t1>=0;t1--)
    {
      x=x*10;
      valstr1=valstr1+((int)(str1[t1])-48)*(x/10);
    }
    x=1;
    valstr2=0; 
    for(t2=long2-1;t2>=0;t2--)
    {
      x=x*10;
      valstr2=valstr2+((int)(str2[t2])-48)*(x/10);
    }
/*判斷輸入的值是否為合法的資料（西元年份的範圍在(1,∞)，月份的範圍在(1,12)）*/ 
    for(t1=0;t1<long1;t1++)
    {
      if(((int)(str1[t1])<48)||((int)(str1[t1])>57)||(valstr1<=0))
      {
        for(t2=0;t2<long2;t2++)
        { 
          if(((int)(str2[t2])<48)||((int)(str2[t2])>57)||(valstr2>12)||(valstr2<=0))
          { 
            printf("不要鬧場= =請你輸入正確的年份");
            break; 
          }
          else
          {
            printf("不要鬧場= =請你輸入正確的年份！\n\n");
            break; 
          } 
        }
        fun=fun+1;
        cho=1;
        break;
      }
    }
    for(t2=0;t2<long2;t2++)
    {
      if(((int)(str2[t2])<48)||((int)(str2[t2])>57)||(valstr2>12)||(valstr2<=0))
      {
        if(cho==1)
        {
          printf("以及月份！\n\n");
        }
        else
        {
          printf("\n不要鬧場= =請您輸入正確的月份！\n\n"); 
        }
        fun=fun+1;
        cho=1;
        break;
      }
    }
/*判斷結束，下面將正確的值放入變數之中，否則重新開始或離開*/ 
    if(cho==0)
    {
      year1=valstr1;
      month1=valstr2;
    }
    else
    {
      switch(fun)
      {
        case 1:
        case 2: 
          { 
            printf("若想要繼續請按個Ｙ，但是請別鬧場，不想玩了請按個Ｎ或ESC離開吧∼\n");
            break; 
          } 
        case 3:
        case 4: 
          { 
            printf("真有你的，還玩，小心沒糖糖吃喔！按個Ｙ繼續或按Ｎ離開吧！\n");
            break; 
          }
        case 5:
        case 6:
          {
            printf("喂喂∼不要欺負我阿，我也是可以用的好不好，請對我溫柔點= =按Ｙ按Ｎ決定是否繼續吧！"); 
            break; 
          }
        case 7:
        case 8:
          {
            printf("不跟你玩了啦！小心交不到女朋友喔！可以按個Ｙ繼續或按Ｎ離開吧∼\n");
            break; 
          }
        case 9:
        case 10:
          {
            printf("給你一個小小懲罰，程式即將強制關閉！若想要繼續使用請重新執行吧！拜拜摟∼\n");
            for(delay=0;delay<500000000;delay++)
            {
              ; 
            } 
            return 0;  
          } 
        default:
          { 
            printf("程式出現錯誤！請按Ｙ繼續或按Ｎ離開。\n");
            break; 
          }
      }
      do
      {
        key=getch();
      }
      while((key!='y')&&(key!='n')&&(key!=27));
      if((key=='n')||(key==27))
      {
        break; 
      }
      else
      { 
        continue;
      } 
    }
    year2=year1-1;
    days=year2*365+year2/4;
    firstday=days%7;
/*取得該月的天數*/
    if(month1<=7)
    {
      if((month1==2)&&((year1%4)==0))
	  {
	    monthdays=29;
	  }
	  else if((month1==2)&&((year1%4)!= 0))
	  {
	    monthdays=28;
	  }
	  else if((month1%2==1)&&(month1!=2))
	  {
	    monthdays=31;
	  }
	  else
	  {
	    monthdays=30;
	  }
    }
    else
    {
      if(month1%2==0)
	  {
	    monthdays=31;
	  }
	  else
	  {
	    monthdays=30;
	  }
    }
/*計算該月的格子數*/
	if(month1<=7)
	{
	  if(month1==1)
	  {
	    spaces=firstday;
	  }
	  else if(month1==2)
	  {
	    spaces=firstday+31;
	  }
	  else if((month1==3)&&((year1%4)==0))
	  {
	    spaces=firstday+29+31;
	  }
	  else if((month1==3)&&((year1%4)!=0))
	  {
	    spaces=firstday+28+31;
	  }
	  else if(((month1%2)==0)&&((year1%4)==0)&&(month1!=3))
	  {
	    spaces=firstday+(month1-1)*30-1+month1/2;
	  }
	  else if(((month1%2)==0)&&((year1%4)!=0)&&(month1!=3))
	  {
	    spaces=firstday+(month1-1)*30-2+month1/2;
	  }
	  else if(((month1%2)==1)&&((year1%4)==0)&&(month1!=1)&&(month1!=2)&&(month1!=3))
	  {
	    spaces=firstday+(month1-1)*30-1+month1/2;
	  }
	  else if(((month1%2)==1)&&((year1%4)!=0)&&(month1!=1)&&(month1!=2)&&(month1!=3))
	  {
	    spaces=firstday+(month1-1)*30-2+month1/2;
	  }
	}
	else
	{
	  if(((month1%2)==0)&&((year1%4)==0))
	  {
	    spaces=firstday+(month1-1)*30-1+month1/2;
	  }
	  else if(((month1%2)==0)&&((year1%4)!=0))
	  {
	    spaces=firstday+(month1-1)*30-2+month1/2;
	  }
	  else if(((month1%2)==1)&&((year1%4)==0))
	  {
	    spaces=firstday+(month1-1)*30-1+month1/2+1;
	  }
	  else if(((month1%2)==1)&&((year1%4)!=0))
	  {
	    spaces=firstday+(month1-1)*30-2+month1/2+1;
	  }
	}
/*計算該月之空格數*/
	space1=spaces%7;
/*給予陣列數值*/
	j=0; 
	for(i=space1;i<=(space1+monthdays-1);i++)
	{
	  j=j+1;
	  mind[i]=j;
	}
/*開始印出日曆*/
  for(x=0;x<=4;x++)
  {
    if(x==0)
    {
      printf("\r開始列印當月月曆."); 
    }
    else if(x==1)
    {
      printf("\r開始列印當月月曆.."); 
    }
    else if(x==2)
    {
      printf("\r開始列印當月月曆..."); 
    }
    else if(x==3) 
    {
      printf("\r開始列印當月月曆...."); 
    }
    else
    {
      printf("\r開始列印當月月曆....完成！"); 
    } 
    for(delay=0;delay<150000000;delay++)
    {
      ;
    }
  }
	printf("\n\n　日　一　二　三　四　五　六\n");
	for(i=0;i<=41;i++)
	{
	  if(mind[i]==0)
	  {
	    printf("　　");
	  }
	  else if((i+1)%7==0)
	  {
        printf("%4d\n",mind[i]);
	  }
	  else
	  {
        printf("%4d",mind[i]);
	  }
	}
/*是否要繼續或離開*/
    printf("\n--------------------\n月曆顯示出來摟∼^^~若想要繼續查看其他月份請按個Ｙ，不想玩了請按Ｎ或ESC離開喲∼\n");
    do
    {
      key=getch();
    }
    while((key!='y')&&(key!='n')&&(key!=27));
    if((key=='n')||(key==27))
    {
      break; 
    }
  }
/*顯示結束標題，並延遲離開*/ 
  printf("\n※程式結束∼即將離開，拜拜摟∼");
  for(delay=0;delay<500000000;delay++)
  {
    ; 
  } 
     return 0; 
}
