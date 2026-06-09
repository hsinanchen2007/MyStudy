
设置不同月份的天数的数组，flag用来标记闰年平年
首先将字符串中的年月日提取出来
判断是否为闰年，若是，flag = 1；
然后将month前面的月份天数相加，再加上day就是该年中的第几天


        int dayOfYear(char * date){
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
            
            char *p = strtok(date, "-");
            int year = atoi(p);
            
            p = strtok(NULL, "-");
            int month = atoi(p);
            
            p = strtok(NULL, "-");
            int day = atoi(p);
            
            if((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0)){
                flag = 1;
            }
            
            int res = 0;
            for(int i = 1; i < month; i++){
                res+=dayOfMonth[i][flag];
            }
            
            res+=day;
            
            return res;
        }