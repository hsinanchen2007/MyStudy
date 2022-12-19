**方法一：HashMap存储计数**
```
class Solution {
    /**
    * 思路：
    * 由题非空数组存在多数元素，所以可以给遍历出现的元素计数，
    * 只要计数超过数组半径，该元素就是当前数组的多数元素。
    */
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        for (int i : nums){
            if(map.containsKey(i)){
                map.put(i,map.get(i)+1);
            }else {
                map.put(i,1);
            }
            if (map.get(i) > nums.length/2){
                return i;
            }
        }
        return 0;
    }
}
```

**方法二：数组排序**
```
class Solution {
    /**
    * 思路：
    * 由题非空数组存在多数元素，
    * 所以对数组排序后，length/2位置的元素就是多数元素。
    */
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```

**方法三：Boyer-Moore投票算法**
```
class Solution {
    /**
    * 思路：
    * 由题存在多数元素，
    * 所以从0开始计数，每出现一次多数元素则计数+1，出现其它元素则计数-1，计数一定为正。
    * (1) 遍历数组，假设count计数为0时候出现的元素为多数元素并记录为ans；
    * (2) 出现相同元素则+1，出现不同元素则-1；
    *   最差情况为所有真实多数元素都+1，其它元素都-1，此时计数为最小正数。
    * (3) 遍历一遍后记录的ans就是正确的多数元素。
    */
    public int majorityElement(int[] nums) {
        int count = 0;
        int ans = 0;

        for (int num : nums) {
            if (count == 0) {
                ans = num;
            }
            count += (num == ans) ? 1 : -1;
        }

        return ans;
    }
}
```
