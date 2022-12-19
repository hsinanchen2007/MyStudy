### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRabbits(int[] answers) {
          int count = 0;
        //key为兔子说的数量，value为有几只兔子说过
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < answers.length; i++) {
            if (answers.length==0) {
                return 0;
            }
            if (answers.length==1) {
                return answers[0]+1;
            }
            int answer = answers[i];
            //查询是否有兔子说过
            Integer num = map.get(answer);
            if (num == null) {
                //没兔子说过就初始化
                map.put(answer,1);
            }else{
                //有兔子说过就给value+1
                map.put(answer,1+num);
            }
        }
        //如果是{1,1,1,1}那么最少有4只兔子如果是{1,1,1,1,1}那么最少有6只兔子
        //遍历map
        for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
            //说的数量
            Integer key = entry.getKey();
            //几只说过
            double value = entry.getValue();
            //最少的兔子数
            double atleastNum = key + 1;
            if (atleastNum<value) {
                double v = value / atleastNum;
                v = Math.ceil(v);
                int v1 = (int) v;
                int atleastNum1 = (int) atleastNum;
                count = count+atleastNum1*v1;

            }else{
                int nums = (int)atleastNum;
                 count = count+nums;

            }

        }
        return count;
    }
}
```