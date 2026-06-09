总逻辑：从1970年1月1日算做周几来着，经过百度，是周五，所以现在首先要做的是算出当前日期与1970年1月1日相差几天，
        然后用天数对7取模，所得的数加上5再对7取模，就是最终的星期
求相差天数：先将每一年的天数确定（通过判断是否是闰年），然后加上最后一年的天数，就可以等到
            （简化运算：一年的天数有365和366天，分别对7取模是1和2，所以在计算天数的时候可以只加1或2）
            判断是否是闰年((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0)
            


```
        char * dayOfTheWeek(int day, int month, int year){
            int flag = 0;
            int dayOfMonth[][2] = {
                0,1,
                31,31,
                28,29,
                31,31,
                30,30,
                31,31,
                30,30,
                31,31,
                31,31,
                30,30,
                31,31,
                30,30,
                31,31
            };
            
            int sum = 0;
            
            for(int i = 1971; i < year; i++){
                if((i%4 == 0 && i%100 != 0 ) || (i % 400 == 0))
                {
                    sum+=2;
                }else{
                    sum+=1;
                }
            }    
            if((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0)){
                flag = 1;
            }
            
            for(int i = 1; i < month; i++){
                
                sum+=dayOfMonth[i][flag];
            }
            
            sum+=day;
            sum--;
            
            int mat = (5 + (sum % 7))%7;
            
            switch(mat){
                case 0:return "Sunday";
                case 1:return "Monday";
                case 2:return "Tuesday";
                case 3:return "Wednesday";
                case 4:return "Thursday";
                case 5:return "Friday";
                case 6:return "Saturday";
                default:
                    return 0;
            }
        }
```
