### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        Deque<String> scoreType = new LinkedList<>();
        int sum = 0;
        if(ops.length == 0){
            return sum;
        }
        for (String type: ops) {
            if("+".equals(type)){
                String t1 = scoreType.pop();
                String t2 = scoreType.peekFirst();

                Integer temp = Integer.parseInt(t1)+Integer.parseInt(t2);
                sum += temp;
                scoreType.push(t1);
                String s = String.valueOf(temp);
                scoreType.push(s);
            }else if("D".equals(type)){
                String temp = scoreType.peekFirst();
                int t = 2 * Integer.parseInt(temp);
                String s = String.valueOf(t);
                scoreType.push(s);
                sum += t;
            }else if("C".equals(type)){
                String temp = scoreType.pop();
                sum -= Integer.parseInt(temp);
            }else {
                sum += Integer.parseInt(type);
                scoreType.push(type);
            }

        }
        return sum;
    }
}
```

维持一个stack，存入每一次得分的数据，
然后依次判断每一个符号是什么，做对应的操作