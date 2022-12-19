单独写了一个getMedian的函数，已经知道有多少项的情况下，可以做的很高效。
```
private double getMedian(int[] count, int cnt) {
        int c = 0;
        boolean even = (cnt % 2 == 0);
        int half = cnt / 2;
        
        for(int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                c += count[i];
                if (c == half) {
                    if (even) {
                        for(int j = i + 1; j < 256; j++) {
                            if (count[j] > 0) {
                                return (j + i) / (double)2;
                            }
                        }
                    
                    } else {
                        for(int j = i + 1; j < 256; j++) {
                            if (count[j] > 0) {
                                return (double) j;
                            }
                        }
                    }
                } else if (c > half) {
                    return (double) i;
                }
            }
        }
        return (double) 0;
    }
    
    public double[] sampleStats(int[] count) {
        int min = -1;
        int max = -1;
        int cnt = 0;
        long sum = 0;
        int mode = -1;
        int modeC = 0;
        for(int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                if (min == -1) {
                    min = i;
                }
                
                if (i > max) {
                    max = i;
                }
                
                cnt += (count[i]);
                sum += (long)(count[i] * i);
                
                if (count[i] > modeC) {
                    modeC = count[i];
                    mode = i;
                }
            }
        }
        
        double[] res = new double[5];
        res[0] = (double) min;
        res[1] = (double) max;
        res[2] = (double) sum / (cnt);
        res[3] = getMedian(count, cnt);
        res[4] = (double) mode;
        
        return res;
    }
```
