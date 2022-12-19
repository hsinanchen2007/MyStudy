```
class Solution {
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        List<String[]> list = new ArrayList<>();
        for(int i = 0; i < timestamp.length; i++)
        {
            String[] temp = new String[3];
            temp[0] = username[i];
            temp[1] = timestamp[i] + "";
            temp[2] = website[i];
            list.add(temp);
        }
        Collections.sort(list, new Comparator<String[]>(){
            public int compare(String[] s1, String[] s2) {
                return Integer.valueOf(s1[1]).compareTo(Integer.valueOf(s2[1]));
            }
        });
        
        Map<String, List<String>> map = new HashMap<>();
        for(String[] arr: list)
        {
            map.putIfAbsent(arr[0], new ArrayList<>());
            map.get(arr[0]).add(arr[2]);
        }
        
        Map<String, Integer> count = new HashMap<>();
        int max = 0;
        String s = "";
        for(String name: map.keySet())
        {
            List<String> temp = map.get(name);
            if(temp.size() < 3)
                continue;
            Set<String> set = new HashSet<>();
            for(int i = 0; i < temp.size() - 2; i++)
            {
                for(int j = i + 1; j < temp.size() - 1; j++)
                {
                    for(int k = j + 1; k < temp.size(); k++)
                        set.add(temp.get(i) + "," + temp.get(j) + "," + temp.get(k));
                }
            }
            for(String str: set)
            {
                count.put(str, count.getOrDefault(str, 0) + 1);
                if(count.get(str) > max)
                {
                    max = count.get(str);
                    s = str;
                }
                else if(count.get(str) == max)
                {
                    if(str.compareTo(s) < 0)
                        s = str;
                }
            }
        }
        return Arrays.asList(s.split(","));
    }
}
```
