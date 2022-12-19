 public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        boolean[] visit = new boolean[nums.length];
        Map<String, String> unique = new HashMap<>();

        Stack<Integer> stack = new Stack<>();
        permuteAll(nums, res, 0, stack, unique, visit);
        System.out.println(res);
        return res;

    }

    private void permuteAll(int[] nums, List<List<Integer>> res, int curSize, Stack<Integer> stack, Map<String, String> uniqueMap, boolean[] visit) {
        if (stack.size() == nums.length) {
            String key = createKey(stack);
            if (!uniqueMap.containsKey(key)) {
                uniqueMap.put(key, key);
                res.add(new ArrayList<>(stack));
            }
        }

        for (int i = 0; i < nums.length; i++) {
            // 没有访问过，添加到栈中
            if (!visit[i]) {
                stack.add(nums[i]);
                visit[i] = true;
                // 递归
                permuteAll(nums, res, curSize + 1, stack, uniqueMap, visit);
                // 状态重置
                stack.pop();
                visit[i] = false;
            }


        }

    }

    private String createKey(Stack<Integer> nums) {

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < nums.size(); i++) {
            sb.append(nums.get(i));
            if (i != nums.size() - 1) {
                sb.append("-");
            }

        }
        return sb.toString();
    }