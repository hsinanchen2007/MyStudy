核心思想：三数要为0的话，一个必定为正，一个必定为负数，判断另一个数的正负然后去对应Map中找
（准备工作）先将nums里的数全部分类添加进两个Map中，一个全放正数，一个全放负数，0单独设置num0来计算个数
（核心工作）通过foreach正Map内foreach负Map，在迭代负Map内进行三数和判定

非原址排序，空间复杂度O(n)
时间复杂度没经过严格证明，应该O(n^2)

欢迎一起讨论

```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int length = nums.length;
        if (length < 3) return result;

        List<List<Integer>> result = new ArrayList<>();
        Map<Integer, Integer> positMap = new HashMap<>();
        Map<Integer, Integer> negatMap = new HashMap<>();
        int num0 = 0;

        for (int n = 0; n < length; n++) {
            // 初始化正负Map和0的数量
            if (nums[n]==0) ++num0;
            if (nums[n]>0) {
                Integer num = positMap.get(nums[n]);
                if (num==null) {
                    positMap.put(nums[n], 1);
                } else {
                    positMap.put(nums[n], num.intValue()+1);
                }
            }
            if (nums[n]<0) {
                Integer num = negatMap.get(nums[n]);
                if (num==null) {
                    negatMap.put(nums[n], 1);
                } else {
                    negatMap.put(nums[n], num.intValue()+1);
                }
            }
        }
        
        // 超过三个0就会出现特殊情况：[0, 0, 0]
        if(num0 >= 3) result.add(new ArrayList<Integer>(Arrays.asList(0, 0, 0)));
        
        // 我在想这里用linkedHashMap会不会好点
        for (Map.Entry positEntry : positMap.entrySet()) {
            int positValue = (Integer) positEntry.getKey();
            int positNum = (Integer) positEntry.getValue();
            for (Map.Entry negatEntry : negatMap.entrySet()) {
                int negatValue = (Integer) negatEntry.getKey();
                int negatNum = (Integer) negatEntry.getValue();
                
                int dValue = 0 - (positValue + negatValue);
                
                // （核心步骤）判断是否成立三元组
                if (dValue == 0 && num0 != 0) {
                    // 两数相加已经为0并且原数组有零
                    result.add(new ArrayList<Integer>(Arrays.asList(negatValue, 0, positValue)));
                }
                if (dValue > 0) {
                    // 需要的值大于零
                    Integer dValueNum = positMap.get(dValue);
                    if (dValueNum != null) {
                        // 需要的数存在
                        if (dValue == positValue) {
                            // 需求值和原值相同
                            if (positNum>1) {
                                result.add(new ArrayList<Integer>(Arrays.asList(negatValue, positValue, positValue)));
                            }
                        } else{
                            // 需求值和原值不同，只有当需求值大于原值时才添加结果，防止重复添加
                            if (dValue > positValue) {
                                result.add(new ArrayList<Integer>(Arrays.asList(negatValue, positValue, dValue)));
                            }
                        }
                    }
                } else {
                    // 需要的值小于零
                    Integer dValueNum = negatMap.get(dValue);
                    if (dValueNum != null) {
                        // 需要的数存在
                        if (dValue == negatValue) {
                            // 需求值和原值相同
                            if (negatNum>1) {
                                result.add(new ArrayList<Integer>(Arrays.asList(negatValue, negatValue, positValue)));
                            }
                        } else{
                            // 需求值和原值不同，只有当需求值小于原值时才添加结果，防止重复添加
                            if (dValue < negatValue) {
                                result.add(new ArrayList<Integer>(Arrays.asList(dValue, negatValue, positValue)));
                            }
                        }
                    }
                }
            }
        }
        
        return result;
        
    }
}
```