### 解题思路
此处撰写解题思路
利用双指针l 和 r进行窗口滑动,当窗口区间[l, r]的和大于目标值 target 时, l++; 小于目标值时, r++; 等于目标值时, 保存当前窗口元素.
循环终止条件是 l >= r.
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList<>();

        for(int l = 1, r = 2, sum = 0; l < r;){
            sum = (l + r) * (r - l + 1) / 2;  // [l, r]为滑动窗口
            if(sum == target){
                int[] temp = new int[r - l + 1];
                for(int i = 0; i < temp.length; i++){
                    temp[i] = l + i;
                }
                list.add(temp);
                l++;

            }else if(sum < target){
                r++;
            }else{
                l++;
            }
        }
        // 返回二维数组
        int[][] result = new int[list.size()][];
        for(int i = 0; i < list.size(); i++){
            result[i] = list.get(i);
        }
        return result;
    }
}
```