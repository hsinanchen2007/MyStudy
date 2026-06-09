### 解题思路
1、很容易看出使用回溯算法进行求解
2、时钟时间的计算采用位运算很方便

### 代码

```java
class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> res = new ArrayList<String>();
        for(int i=0;i<=num;i++){
            List<Integer> hours = new ArrayList<Integer>();
            List<Integer> minutes = new ArrayList<Integer>();
            dfs(0,12,0,i,0,4,hours);
            dfs(0,60,0,num-i,0,6,minutes);
            for(int j=0;j<hours.size();j++){
                for(int k=0;k<minutes.size();k++){
                    String str = hours.get(j)+":";
                    int value = minutes.get(k);
                    if(value<10){
                        str = str+"0"+value;
                    }else{
                        str = str+value;
                    }
                    res.add(str);
                }
            }
        }
        return res;
    }

    /*
    * value记录当前的时间数值
    * max 当前时间所允许的最大值
    * m 当前亮灯的个数
    * num 要求的亮灯个数
    * curOffSet 当前的偏移量
    * offset 二进制所允许的偏移量
    */
    public void dfs(int value, int max, int m, int num, int curOffSet, int offset, List<Integer> list){
        if(m>num) return;
        if(m==num){
            list.add(value);
            return;
        }
        for(int i=curOffSet;i<offset;i++){
            int temp = 1<<i;//二进制手表，当然要进行位运算了
            int tpValue = value|temp;
            if(tpValue==value) continue;//与原数没变化，继续进行循环
            if(tpValue>=max) continue;
            dfs(tpValue,max,m+1,num,i+1,offset,list);
        }
    }
}
```