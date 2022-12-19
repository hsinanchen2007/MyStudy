其实是这位[cieusy](https://leetcode-cn.com/problems/cinema-seat-allocation/solution/cha-zhao-by-cieusy/)大佬做出来的。看到最多上手就是dp，我真魔怔了。额外写个题解是想借此记录下来，不枉我死磕这么久。
首先，可以确定，没有预约的排会有2个家庭。
然后，对于有预约的排，判断可以安排几个家庭。 可能会有两种情况：
1，满足（2，3， 4，5）以及 （6. 7， 8， 9） 可以安排2个家庭
2，只满足 （2，3， 4，）|（6. 7， 8， 9） | （4， 5， 6， 7），安排一个家庭
```
  public int maxNumberOfFamilies(int count, int[][] reservedSeats) {
        int m = count;
        int n = 10;
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int[] nums : reservedSeats) {
            Set<Integer> list = map.getOrDefault(nums[0], new HashSet<>());
            list.add(nums[1]);
            map.put(nums[0], list);
        }
        int cnt = 0;
        //在已经预约的行中最多能放几个
        for(Set set : map.values()){
            boolean flag = false;
            if(!set.contains(2) && !set.contains(3)&&!set.contains(4) && !set.contains(5)){
                cnt++;
                flag = true;
            }
            if(!set.contains(6) && !set.contains(7)&&!set.contains(8) && !set.contains(9)){
                cnt++;
                flag = true;
            }
            if(!set.contains(4) && !set.contains(5)&&!set.contains(6) && !set.contains(7) && !flag) {
                cnt++;
            }
        }
        return cnt + 2 * (m - map.size());
    }
```
再次感谢那位老哥，不然今天都不想睡了，至于位运算等我清醒再说吧。