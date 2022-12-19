首先根据每位用户所在用户组的大小进行分类，即所在用户组大小相同的用户分在同一类，通过`Map<Integer, List<Integer>>`实现分类。然后根据该用户组大小的用户数量决定是否要把该类用户拆分成多组，如果该类用户数量等于用户组大小则就是一组不做拆分，如果该类用户数量大于用户组大小则需要拆分成多个用户组，每个用户组的用户数量等于用户组大小，由于题目给出的数据保证至少存在一种解决方案，所以可以直接用该类用户数量除以用户组大小得到需要拆分成的用户组数。例如，用户组大小为3的用户共有6个，则这6个用户拆分成2个用户组。
```
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, List<Integer>> sizePeopleMap = new HashMap<Integer, List<Integer>>();
        int length = groupSizes.length;
        for (int i = 0; i < length; i++) {
            int groupSize = groupSizes[i];
            List<Integer> people = sizePeopleMap.getOrDefault(groupSize, new ArrayList<Integer>());
            people.add(i);
            sizePeopleMap.put(groupSize, people);
        }
        List<List<Integer>> groups = new ArrayList<List<Integer>>();
        Set<Integer> keySet = sizePeopleMap.keySet();
        for (int groupSize : keySet) {
            List<Integer> people = sizePeopleMap.get(groupSize);
            int size = people.size();
            if (size == groupSize)
                groups.add(people);
            else {
                int groupsCount = size / groupSize;
                for (int i = 0; i < groupsCount; i++) {
                    List<Integer> group = new ArrayList<Integer>();
                    int start = i * groupSize, end = (i + 1) * groupSize - 1;
                    for (int j = start; j <= end; j++)
                        group.add(people.get(j));
                    groups.add(group);
                }
            }
        }
        return groups;
    }
}
```

