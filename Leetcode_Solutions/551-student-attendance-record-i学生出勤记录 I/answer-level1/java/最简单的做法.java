```
    题解：满足这道题的条件是第一，A大于1个，L连续大于2个。
    第一个条件只需要用一个整型a保存A存在的数量，第二个条件需要用到两个整数变量，一个代表当前的元素为L时的下标，一个l代表L元素连续存在的数量。
    for循环遍历字符串S，a值大于1时返回false.当l大于2时返回false,否则当遇到元素为‘A’时加一。
    当遇到元素为‘L’时并且表示上一个元素是L时的下标是-1或者是i-1时，l加一。循环结束程序返回true.
     public boolean checkRecord(String s) {
        int a = 0;
        int l = 0;
        int index = -1;
        for (int i = 0;i<s.length();i++){
            if('A'==s.charAt(i))a++;
            if('L'==s.charAt(i)){
                if(index==-1||index==i-1){
                    index = i;l++;
                }else{
                    index = i;l=1;
                }
            }
            if(l>2)return false;
            if(a>1){
                return false;
            }
        }
        return true;
    }
```
