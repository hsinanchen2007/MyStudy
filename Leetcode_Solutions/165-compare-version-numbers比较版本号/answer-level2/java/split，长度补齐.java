```
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] split1 = version1.split("\\.");
        String[] split2 = version2.split("\\.");

        if(split1.length < split2.length){
            split1 = Arrays.copyOf(split1, split2.length);
        }else if(split1.length > split2.length){
            split2 = Arrays.copyOf(split2, split1.length);
        }

        for (int i = 0; i < split1.length; i++) {
            if(split1[i] == null){
                split1[i] = "0";
            }

            if(split2[i] == null){
                split2[i] = "0";
            }
        }

        int index1 = 0, index2 = 0;
        while (index1 < split1.length && index2 < split2.length) {
            if (Integer.parseInt(split1[index1]) < Integer.parseInt(split2[index2])) {
                return -1;
            } else if (Integer.parseInt(split1[index1]) > Integer.parseInt(split2[index2])) {
                return 1;
            } else {
                index1++;
                index2++;
            }
        }


        return 0;
    }
}
```
