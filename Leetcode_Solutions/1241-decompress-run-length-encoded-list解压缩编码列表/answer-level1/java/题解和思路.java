### 题目意思
每一对都表示解压后有 a 个值为 b 的元素。比如3,4，就是3个4，得出的数组是[4,4,4],每个小数组按顺序合并并返回就行了
### 解题思路
先将数组长度n，迭代n/2次，每次把a个b值放进list，然后转成数组输出

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        List temp = new ArrayList<Integer>();
        for(int i = 0; i < nums.length/2; i ++){
            int[] ele = {nums[2*i], nums[2*i+1]};
            for(int j = 1; j <= ele[0]; j++){
            	temp.add(ele[1]);
            }
        }
        int[] res = new int[temp.size()];
        for(int i = 0; i<temp.size(); i++){
        	res[i] = (int)temp.get(i);
        }
        return res;
    }
}
```