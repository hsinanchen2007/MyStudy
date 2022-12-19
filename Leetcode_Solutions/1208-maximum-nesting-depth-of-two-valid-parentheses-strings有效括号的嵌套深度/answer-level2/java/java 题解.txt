今天的题目有点懵，感觉啥也没考到。。。（java流程控制？）
```
 public int[] maxDepthAfterSplit(String seq) {

        int n = seq.toCharArray().length;
        int[] res = new int[n];

        boolean isProisA = false;
        boolean isNextB = false;

        for (int i = 0; i < n; i++) {
            if (seq.charAt(i) == '(') {
                if (!isProisA) {
                    res[i] = 0;
                    isProisA = true;
                } else {
                    res[i] = 1;
                    isProisA = false;
                }
            } else {
                if (!isNextB) {
                    res[i] = 0;
                    isNextB = true;
                } else {
                    res[i] = 1;
                    isNextB = false;
                }


            }
        }
        return res;


    }
```
