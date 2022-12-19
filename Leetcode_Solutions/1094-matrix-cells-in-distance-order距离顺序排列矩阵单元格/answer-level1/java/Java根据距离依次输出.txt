![image.png](https://pic.leetcode-cn.com/6ad775fc0694de691fc971b8e844f2dbb94259d89d14fa692a5a3eb0dba91cfd-image.png)

        int[] l = new int[4];
        l[0] = r0 + c0;
        l[1] = r0 + C - 1 - c0;
        l[2] = R - 1 - r0 + c0;
        l[3] = R - 1 - r0 + C - 1 - c0;
        int m = 0;
        for(int i : l) {
            if(i > m) {
                m = i;
            }
        }
        
        int[][] ref= new int[R * C][2];
        int idx = 1;
        ref[0][0] = r0;
        ref[0][1] = c0;
        for(int i = 1; i <= m; i++) {
            for(int x = 0; x <= i; x++) {
                if(r0 - x >= 0 && c0 - (i - x) >= 0) {
                    ref[idx][0] = r0 - x;
                    ref[idx++][1] = c0 - (i - x);
                }
                if(r0 + x <= R - 1 && c0 - (i - x) >= 0 && x != 0 && i != x) {
                    ref[idx][0] = r0 + x;
                    ref[idx++][1] = c0 - (i - x);              

                }
                if(r0 - x >= 0 && c0 + (i - x) <= C - 1  && x != 0 && i != x) {
                    ref[idx][0] = r0 - x;
                    ref[idx++][1] = c0 + (i - x);              

                }
                if(r0 + x <= R - 1 && c0 + (i - x) <= C - 1) {
                    ref[idx][0] = r0 + x;
                    ref[idx++][1] = c0 + (i - x);         

                }
            }    
        }
        return ref;
