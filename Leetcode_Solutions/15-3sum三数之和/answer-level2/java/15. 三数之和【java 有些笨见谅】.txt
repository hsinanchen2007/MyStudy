```
        // 返回结果集
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        // 用于判断组合重复情况
        List<String> distinctLt = new ArrayList<String>();
        // 组合第一个数 i
        for(int i = 0; i < nums.length; i++) {
            // 组合第二个数 j
            for(int j = 0; j < nums.length; j++){
                // 不能重复下标
                if(i == j){
                    continue;
                }
                // 组合第三个数 k
                for(int k = 0; k < nums.length; k++){
                    // 不能重复下标
                    if(i == k || j == k){
                        continue;
                    }
                    // 判断组合条件  a + b + c = 0
                    if(nums[i] + nums[j] + nums[k] == 0){
                        // 值从小到大排序 toString 判断组合是否重复
                        List<Integer> ex = new ArrayList<Integer>();
                        ex.add(nums[i]);
                        ex.add(nums[j]);
                        ex.add(nums[k]);
                        Collections.sort(ex); // 排序
                        System.out.println(ex.toString());
                        if (distinctLt.contains(ex.toString())) {
                            // 重复
                        }
                        else {
                            // 添加到判断重复集合
                            distinctLt.add(ex.toString());
                            // 添加到结果集
                            res.add(ex);
                        }
                    }
                }
            }
        }
        return res;
```
