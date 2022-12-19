### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {

        int len = target / 2 + 1;

        //从1开始
        int i = 1, j = 1;
        List<int[]> list = new ArrayList<>();
        while(i <= j && j <= len){

            if(target > ((i + j) * (j - i + 1) >> 1))
                j++;
            else if(target < ((i + j) * (j - i + 1) >> 1))
                i++;
            else{
                int [] res = new int [j - i + 1];
                for(int k = i; k <= j; k++)
                    res[k - i] = k;   
                list.add(res);
                //改变一个指针，避免死循环
                j++;
            }
        }
        int [][] res = new int[list.size()][];
        for(int n = 0; n < list.size(); n++){
            res[n] = list.get(n);
        }
        return res;
    }
}
```