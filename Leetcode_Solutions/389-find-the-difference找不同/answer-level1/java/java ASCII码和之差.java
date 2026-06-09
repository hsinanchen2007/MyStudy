    class Solution {
        public char findTheDifference(String s, String t) {
            char a[] = s.toCharArray();
            char b[] = t.toCharArray();
            int re = (int)b[b.length-1];
            int m = 0;
            for(int i=0;i<a.length;i++){
                m+=(int)a[i];
                re+=(int)b[i];
            }
            return (char)(re-m);
        }
    }