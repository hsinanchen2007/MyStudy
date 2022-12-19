class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        Map<Integer, List<List<Integer>>> map = new HashMap();
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                List<Integer> list = new ArrayList();
                list.add(i);
                list.add(j);
                int twoSum = nums[i] + nums[j];
                List<List<Integer>> indexList = map.get(twoSum);
                if (indexList == null) {
                    indexList = new ArrayList<>();
                }
                indexList.add(list);
                map.put(twoSum, indexList);
            }
        }

        List<List<Integer>> resultList = new ArrayList<>();
        Set<String> set = new HashSet<>();
        map.forEach((twosum, listList) -> {
            int diff = target - twosum;
            List<List<Integer>> listsFind = map.get(diff);
            if (listsFind!=null){
                listList.forEach(listOut -> {
                    listsFind.forEach(listInner -> {
                        if (listInner.get(0) > listOut.get(0) && listInner.get(0) > listOut.get(1) && listInner.get(1) > listOut.get(0) && listInner.get(1) > listOut.get(1)
                                &&listInner.get(0)>listInner.get(1)&&listOut.get(0)>listOut.get(1)) {
                            String key = new StringBuilder().append(nums[listInner.get(0)]).append(nums[listInner.get(1)]).append(nums[listOut.get(0)]).append(nums[listOut.get(1)]).toString();
                            if (!set.contains(key)) {
                                set.add(key);
                            } else {
                                return;
                            }
                            List<Integer> resultItem = new ArrayList<>();
                            resultItem.add(nums[listInner.get(0)]);
                            resultItem.add(nums[listInner.get(1)]);
                            resultItem.add(nums[listOut.get(0)]);
                            resultItem.add(nums[listOut.get(1)]);
                            resultList.add(resultItem);
                        }
                    });
                });
            }

        });
        return resultList;
    }

}