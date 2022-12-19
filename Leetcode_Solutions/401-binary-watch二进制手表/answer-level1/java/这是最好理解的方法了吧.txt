思路：这是一个典型的递归回溯题目
当num=1时，
            有2种情况  
                      （1，0）（1，2，4，8） --  0
                      （0，1） 0 --（1，2，4，8，16，32）/小时灯亮，时间灯不亮
当num=2时,  (2,0)小时灯亮，分钟灯不亮 （1+2，1+4，1+8，2+4，4+8）  --  0
                                     注意：由于时间为0-11将4+8这种情况排除
           (0,2)分钟灯亮，小时灯不亮   0 --（1+2，1+4，1+8，1+16，1+32，2+4......） 
           (1,1)小时灯和分钟灯各亮一个（1，2，4，8）--（1，2，4，8，16，32）
于是我们可以采用 双重for来控制  小时灯LEDNumber、分钟灯num-LEDNumber亮的个个数，
```
for (int LEDNumber = 0; LEDNumber <= num; LEDNumber++) {
            hour.clear();
            min.clear();
            getHour(LEDNumber,list,0);
            getMin(num-LEDNumber,list,0);
            for (int i = 0; i < hour.size(); i++) {
                for (int j = 0; j < min.size(); j++) {
                    strList.add( toTime(hour.get(i),min.get(j)));
                }
            }
        }
            return strList;
        }
```
接下来就用回溯得到小时灯时对应的时间和分钟灯亮时对应的时间，组合可得到答案。     
```
    private  int [] s={1,2,4,8};
    private  int [] m={1,2,4,8,16,32};
    private List<String> strList=new ArrayList<>();
    private List<Integer> hour=new ArrayList<>();
    private List<Integer> min=new ArrayList<>();
    public List<String> readBinaryWatch(int num) {
        if (num<0){
            return strList;
        }
        if (num==0){
            strList.add("0:00");
            return strList;
        }
        LinkedList<Integer> list=new LinkedList<>();
        for (int LEDNumber = 0; LEDNumber <= num; LEDNumber++) {
            hour.clear();
            min.clear();
            getHour(LEDNumber,list,0);
            getMin(num-LEDNumber,list,0);
            for (int i = 0; i < hour.size(); i++) {
                for (int j = 0; j < min.size(); j++) {
                    strList.add( toTime(hour.get(i),min.get(j)));
                }
            }
        }
            return strList;
        }
    public void getHour(int num,LinkedList<Integer> list,int start){
        if (list.size()==num){
            int sum=0;
            for (Integer i : list) {
                sum+=i;
            }
            if (sum<12){
                hour.add(sum);
            }
            return;
        }
        for (int i = start; i < 4; i++) {
            list.addLast(s[i]);//1,2,4,8
            getHour(num,list,i+1);
            list.removeLast();
        }
        return;
    }
    public void getMin(int num,LinkedList<Integer> list,int start){
        if (list.size()==num){
            int sum=0;
            for (Integer i : list) {
                sum+=i;
            }
           if (sum<60){
               min.add(sum);
           }
            return;
        }
        for (int i = start; i < 6; i++) {
            list.addLast(m[i]);
            getMin(num,list,i+1);//0
            list.removeLast();
        }
        return;
    }
    public String toTime(int hour,int min){
        String res="";
        if (min<10){
             res=hour+":0"+min;
        }else {
            res=hour+":"+min;
        }
        return res;
    }

```
