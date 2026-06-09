算法思想：
初始：[]
加1：[] [1]
加2：[] [1] ***[2] [1,2]***
加3：[] [1] [2] [1,2] ***[3] [1,3] [1,2] [1,2,3]***
加4：[] [1] [2] [1,2] [3] [1,3] [1,2] [1,2,3] ***[4] [1,4] [2,4] [1,2,4] [3,4] [1,3,4] [1,2,4] [1,2,3,4]***
...

    public List<List<Integer>> subsets02(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        ans.add(new ArrayList<Integer>());//加[]
        for (int i = 0; i < nums.length; i++) {//每次增加一个数字
            int lenCur = ans.size();
            for (int j = 0; j < lenCur; j++) {//每个已有子集新增一个数
                List<Integer> newList = new ArrayList<>();
                newList.addAll(ans.get(j));
                newList.add(nums[i]);
                ans.add(newList);
            }
        }
        return ans;
    }