就是这么任性，就是这么暴力，你咬我？

```
class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> ans = new ArrayList<String>();
        String[][] hstrs = {{"0"}, {"1","2","4","8"}, {"3","5","6","9","10"}, {"7","11"}};
        String[][] mstrs = {{"00"}, {"01","02","04","08","16","32"}, {"03","05","06","09","10","12","17","18","20","24","33","34","36","40","48"}, {"07","11","13","14","19","21","22","25","26","28","35","37","38","41","42","44","49","50","52","56"}, {"15","23","27","29","30","39","43","45","46","51","53","54","57","58"}, {"31","47","55","59"}};

        for(int i = 0; i <= Math.min(3,num); i++) {
            if (num - i > 5) continue;
            String[] hstr = hstrs[i];
            String[] mstr = mstrs[num - i];
            for(int j = 0; j < hstr.length; j++) {
                for(int k = 0; k < mstr.length; k++) {
                    ans.add(hstr[j] + ":" + mstr[k]);
                };
            };
        };
        return ans;

    }
}
```
