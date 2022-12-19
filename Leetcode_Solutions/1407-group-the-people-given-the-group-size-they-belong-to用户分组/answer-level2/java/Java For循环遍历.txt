    public static List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> res = new ArrayList<>();

        for (int i = 0; i < groupSizes.length; i++) {
            // 如果当前值为0，则继续遍历
            if (groupSizes[i] == 0) {
                continue;
            }
            // 先将当前的序号加入列表
            List<Integer> countList = new ArrayList<>();
            countList.add(i);
            // 如果当前分组为一，则直接将该列表加入结果集
            if (groupSizes[i] == 1) {
                res.add(countList);
                continue;
            }

            // 从i+1 开始遍历，取集合数相等的序号
            for (int j = i + 1; j < groupSizes.length; j++) {

                // 如果所在组元素相等，且当前列表数量还尚未达到目标成员数，则将序号加入列表
                if (groupSizes[i] == groupSizes[j] && countList.size() < groupSizes[i]) {
                    countList.add(j);
                    groupSizes[j] = 0;
                }
                // 如果当前列表数量已经达到目标成员数，则将列表加入结果集
                if (countList.size() == groupSizes[i]) {
                    res.add(countList);
                    break;
                }
            }
        }

        return res;
    }