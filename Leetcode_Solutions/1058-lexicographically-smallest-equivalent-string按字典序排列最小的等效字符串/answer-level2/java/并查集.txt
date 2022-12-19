将等价字符并入一个集合
```
class Solution {
        int[] alphabet = new int[26];
        public String smallestEquivalentString(String A, String B, String S) {
            for (int i=0;i<26;++i)
                alphabet[i]=i;

            for (int i=0;i<A.length();i++){
                union(A.charAt(i)-'a',B.charAt(i)-'a');
            }

            StringBuilder sb = new StringBuilder();

            for (int i=0;i<S.length();i++){
                char c = S.charAt(i);

                sb.append((char)(findSmall(c-'a')+'a'));
            }

            return sb.toString();
        }

        private int findSmall(int i){
            while (alphabet[i]!=i){
                i = alphabet[i];
            }

            return i;
        }

        private void union(int a,int b){
            int aa = findSmall(a);
            int bb = findSmall(b);
            int small = Math.min(aa,bb);

            alphabet[bb] = small;
            alphabet[aa] = small;
        }
    }
```