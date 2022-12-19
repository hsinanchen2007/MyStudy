方法1：二分查找
![image.png](https://pic.leetcode-cn.com/00cc1e166679952f3613910bc98f9ba0f854d6c9a05fea572d3a4cce2d46dec5-image.png)
```
    class Solution {
        public int[] twoSum(int[] numbers, int target) {
            int[] res = new int[2];
            for (int i = 0; i <numbers.length ; i++) {
                int index2=binarySearch(numbers,target-numbers[i],i+1);
                if (index2>0){
                    res[0] = i+1;
                    res[1] = index2+1;
                    return res;
                }
            }
            return res;
        }

        private int binarySearch(int[] numbers, int target2, int j) {
            int low=j,high=numbers.length-1;
            int mid;
            while (low<=high){
                mid = low + ((high-low)>>>1);
                if (numbers[mid]==target2)
                    return mid;
                else if (numbers[mid]<target2)
                    low = mid +1;
                else high = mid-1;
            }
            return -1;
        }
    }
```
最开始想到的方法，遍历一次，每次都按照二分法查找第二个数，效率不是很高

方法2：
第二种采用hashmap存储数值和下标，效率更差了
![image.png](https://pic.leetcode-cn.com/13be715bfc36efa44f28a84f5d27804f1d7e71e528c36a8986dc146f0981efc0-image.png)
```
class Solution {
        public int[] twoSum(int[] numbers, int target) {
            int[] res = new int[2];
            HashMap<Integer,Integer> hashMap = new HashMap<>();
            for (int i = 0; i <numbers.length ; i++) {
                hashMap.put(numbers[i],i+1);
            }
            for (int i = 0; i <numbers.length ; i++) {
                if (hashMap.containsKey(target-numbers[i])){
                    res[0] = i+1;
                    res[1] = hashMap.get(target-numbers[i])+1;
                    return res;
                }
            }
            return res;
        }
    }
```

方法3：
看了官方解题的双指针，写了一下，发现这个思路是真的牛逼
![image.png](https://pic.leetcode-cn.com/1cc2bdf39d30791bef49b6cdb8d95f7264bd1ef0235d6425a4e2df393c0bbec7-image.png)
```
    class Solution{
        public int[] twoSum(int[] numbers, int target) {
            int i=0,j=numbers.length-1;
            int[] res = new int[2];
            while (i<j){
                if (numbers[i]+numbers[j]==target){
                    res[0] = i+1;
                    res[1] = j+1;
                    return res;
                }else if (numbers[i]+numbers[j]<target)
                    i++;
                else j--;
            }
            return res;
        }
    }
```
