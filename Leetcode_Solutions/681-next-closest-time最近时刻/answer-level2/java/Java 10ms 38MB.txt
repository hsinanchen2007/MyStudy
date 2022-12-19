### 解题思路
不用ide果然代码比较丑，白板写题bugfree挑战第一题。

### 代码

```java
class Solution {
    public String nextClosestTime(String time) {
        Set<Integer> appears = new HashSet<>();
        for (char i: time.toCharArray()){
            if (i==':'){
                continue;
            }
            appears.add(i-'0');
        }
        List<Integer> hours = new LinkedList<>();
        List<Integer> mins = new LinkedList<>();
        for (int i:appears){
            for (int j:appears){
                if (10*i+j>=60) continue;
                if (10*i+j>=24) {
                    mins.add(10*i+j);
                }else{
                    mins.add(10*i+j);
                    hours.add(10*i+j);
                }
            }
        }
        Collections.sort(hours);
        Collections.sort(mins);

        String[] input = time.split(":");
        int inhours = Integer.parseInt(input[0]);
        int inmins = Integer.parseInt(input[1]);

        int indexin = mins.indexOf(inmins);
        int indexhours = mins.indexOf(inhours);
        int nextmin = 0;
        int nexthour = 0;
        if (indexin!=mins.size()-1){
             nextmin = mins.get(indexin+1);
             return input[0]+":"+intToString(nextmin);
        }else{
            if (indexhours == hours.size()-1){
                nextmin = mins.get(0);
                nexthour = hours.get(0);
                return intToString(nexthour)+":"+intToString(nextmin);
            }else{
                nextmin = mins.get(0);
                nexthour = hours.get(indexhours+1);
                return intToString(nexthour)+":"+intToString(nextmin);
            }
        }
    }

    private String intToString(int x){
        if (x<10) return "0"+x;
        else return String.valueOf(x);
    }
}
```