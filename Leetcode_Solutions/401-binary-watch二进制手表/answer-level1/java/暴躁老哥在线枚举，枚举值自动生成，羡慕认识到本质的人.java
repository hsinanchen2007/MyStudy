```java
public List<String> readBinaryWatch(int num) {

        int[] nums = new int[]{8,4,2,1};
        List<List<Integer>> h = new ArrayList<>();
        help(nums, 0, 0, 1, 12, h);
        h.get(0).add(0);

        nums = new int[]{32, 16, 8, 4, 2, 1};
        List<List<Integer>> m = new ArrayList<>();
        help(nums, 0, 0, 1, 60, m);
        m.get(0).add(0);

        List<String> rs = new ArrayList<>();

        for(int i = 0; i <= 3 && i <= num; i++){
            if(num - i > 5) continue;
            for (int j : h.get(i)) {
                for (int k : m.get(num - i)) {
                    if (k >= 10) rs.add(j + ":" + k);
                    else rs.add(j + ":0" + k);
                }
            }
        }
        return rs;
    }

    public void help(int[] nums, int v, int start, int level, int max, List<List<Integer>> rs){
        for(int i = start; i < nums.length; i++){
            int value = v + nums[i];
            if(value < max) {
                while(rs.size() <= level) rs.add(new ArrayList<>());
                rs.get(level).add(value);
                help(nums, value, i + 1, level + 1, max, rs);
            }
        }
    }
```