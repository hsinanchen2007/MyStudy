### 解题思路
此处撰写解题思路
好腦殘 遍歷計算出數組長度後就不用用集合了，那樣的話就快多了
### 代码

```java
class Solution {
 public int[] decompressRLElist(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if ((i)%2==0){
                for (int j = 0; j < nums[i]; j++) {
                    arr.add(nums[i+1]);
                }
            }
        }
        int[] newnum = new int[arr.size()];
        for (int i = 0; i < arr.size(); i++) {
            newnum[i]=arr.get(i);
        }
        return newnum;

    }
}
```