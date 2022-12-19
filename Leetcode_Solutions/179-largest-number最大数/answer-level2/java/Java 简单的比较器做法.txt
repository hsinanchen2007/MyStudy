```
class Solution {
  public String largestNumber(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        Collections.sort(list, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                String a = String.valueOf(o1);
                String b = String.valueOf(o2);
                if (a.equals(b)) return 0;
                String c = a + b;
                String d = b + a;
                for (int i = 0; i < c.length(); i++) {
                    if (c.charAt(i) > d.charAt(i)) {
                        return -1;
                    }
                    if (c.charAt(i) < d.charAt(i)) {
                        return 1;
                    }

                }
                return 0;
            }
        });
        StringBuilder sb = new StringBuilder();
        for (Integer integer : list) {
            sb.append(integer);
        }
        String res = sb.toString();
        while (res.length() > 1 && res.charAt(0) == '0') res = res.substring(1, res.length());
        return res;


    }
}
```
