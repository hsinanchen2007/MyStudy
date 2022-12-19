```
public int numSteps(String s) {
        int res = 0;
        int len = s.length();
        int i = len - 1;
        char[] array = s.toCharArray();
        while(i >= 0) {
            if (i == 0) {
                if (array[i] != '1') {
                    res++;
                }
                break;
            }
            
            res++;
            if (array[i] == '0') {
                i--;
            } else {
                array[i] = '0';
                for(int j = i - 1; j >=0; j--) {
                    if (array[j] == '1') {
                        array[j] = '0';
                    } else {
                        array[j] = '1';
                        break;
                    }
                }
            }
        }
        
        return res;
    }
```
