# 解题思路
1. 暴力法：四层for循环，时间复杂度是O(N^4)
2. 模拟两数之和，采用双指针，时间复杂度是O(N^3)。防止重复需要判断
3. 如何才能O(N^2)呢？需要将两层循环拍平，拍成一层循环，那么就可以达到O(N^2).
可以将2层的数字预先计算求和，存储到哈希表里方便快速查找。防止重复可以用集合

# 双指针：O(N^3)
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ret = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        
        int start = 0;
        int end = n-1;
        for (int i = start; i < n-3; i++){
            if (i > start && nums[i] == nums[i-1]){    // 确保i不重复
                continue;
            }
            for (int j = i+1; j < n-2; j++){
                if (j > (i+1) && nums[j] == nums[j-1]){    // 确保i不重复
                    continue;
                }
                int k = j+1;
                int l = n-1;
                while (k < l){
                    if (k > (j+1) && nums[k] == nums[k-1]){   // 确保k不重复
                        k++;
                        continue;
                    }
                    if (l < (n-1) && nums[l] == nums[l+1]){   // 确保l不重复
                        l--;
                        continue;
                    }
                    int s = nums[i] + nums[j] + nums[k] + nums[l];
                    if (s == target){
                        ret.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                        k++;
                        l--;
                    } else if (s < target){
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        
        return ret;
    }
}
```

# 哈希表：O(N^2)
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        HashMap<Integer, List<List<Integer>>> t = new HashMap<>();
        HashSet<List<Integer>> ret = new HashSet<>();
        Arrays.sort(nums);
        int n = nums.length;
        
        int start = 0;
        int end = n-1;
        for (int i = start; i <= end-1; i++){
            for (int j = i+1; j <= end; j++){
                int s = nums[i] + nums[j];
                List<Integer> tmp = new ArrayList<>();
                tmp.add(i);
                tmp.add(j);
                if (t.containsKey(s)){
                    // TODO:
                    List<List<Integer>> tmp1 = t.get(s);
                    tmp1.add(tmp);
                    t.put(s, tmp1);
                } else {
                    // TODO:
                    List<List<Integer>> tmp1 = new ArrayList<>();
                    tmp1.add(tmp);
                    t.put(s, tmp1);
                }
            }
        }
        
        start = 0;
        end = n-1;
        for (int i = start; i <= end-1; i++){
            for (int j = i+1; j <= end; j++){
                int s = target-(nums[i] + nums[j]);
                if (t.containsKey(s)){
                    // TODO:
                    for (List<Integer> pairs: t.get(s)){
                        int k = pairs.get(0);
                        int l = pairs.get(1);
                        if (j != k && j != l && i != k && i != l){
                            List<Integer> tmp = new ArrayList<>();
                            tmp.add(nums[k]);
                            tmp.add(nums[l]);
                            tmp.add(nums[i]);
                            tmp.add(nums[j]);
                            tmp.sort(Comparator.comparingInt(o -> o));
                            ret.add(tmp);
                        }
                    }
                }
            }
        }
        return new ArrayList<>(ret);
    }
}
```

