### 解题思路
- 使用简单的数学逻辑：
对于以-2为基数时，当值为1,1时，即(-2)^x * 2 + (-2)^(x+1) = 0，即

        1
    +   1
结果为：-1 0 = 1 1 0
- 使用pre保存进位的数，使用num保存当前位相加结果
num = arr[i] + arr[j] + pre
- 那么num的取值有以下几种情况

| num | 解释 | pre | 当前位 |
|--|--|--|--|
|-1| 表示需要向前借位 | 1 | 1 |
| 0| 表示刚好抵消 | 0 | 0 |
| 1| 表示多余1位  | 0 | 1 |
| 2| 表示过多需要抵消 | -1 | 0 |
| 3| 表示过多需要抵消 | -1 | 1 |

- 最后去掉前导0
- 从后往前得到最终结果
    

### 代码

```java
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        List<Integer> list = new ArrayList();
        int i = arr1.length-1;
        int j = arr2.length-1;
        int pre = 0;
        while(i >= 0 || j >= 0){
            int num = 0;
            if(i < 0){
                //只剩arr2
                num = pre + arr2[j--];
            }else if(j < 0){
                //只剩arr1
                num = pre + arr1[i--];
            }else {
                num = pre + arr1[i--]+arr2[j--];
            }
            //不同情况分类
            switch(num){
                case -1:
                    list.add(1);
                    pre = 1;
                    break;
                case 0:
                    list.add(0);
                    pre = 0;
                    break;
                case 1:
                    list.add(1);
                    pre = 0;
                    break;
                case 2:
                    list.add(0);
                    pre = -1;
                    break;
                case 3:
                    list.add(1);
                    pre = -1;
                    break;
            }
        }
        //最后还差时
        if(pre == -1){
            list.add(1);
            list.add(1);
        }
        int k = 0;
        //去掉前导0
        for(; k < list.size() && list.get(list.size()-1-k) == 0; k++);
        if(list.size()-k == 0) return new int[1];
        int[] result = new int[list.size()-k];
        int index = 0;
        //结果
        for(; k < list.size(); k++){
            result[index++] = list.get(list.size()-1-k);
        }
        return result;
    }
}
```