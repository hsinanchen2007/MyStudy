    class Solution {
        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            List<List<Integer>> lists = new ArrayList<>();
            List<Integer> list = new ArrayList<>();
            backTrack(candidates, lists, list, target);

            return lists;
        }


        private void backTrack(int[] candidates, List<List<Integer>> lists, List<Integer> list, int left) {
            if (left < 0) { //说明已经超了，返回
                return;
            } else if (left == 0) { //找到匹配的
                lists.add(new ArrayList<>(list));
                return;
            }

            for (int i = 0; i < candidates.length; i++) {
                //去重处理， 去除后面元素小于前面元素的情况
                if (list.size() > 0 && list.get(list.size() - 1) > candidates[i]) {
                    continue;
                }
                    
                list.add(candidates[i]);
                backTrack(candidates, lists, list, left - candidates[i]);
                list.remove(list.size() - 1);

            }
        }
    }