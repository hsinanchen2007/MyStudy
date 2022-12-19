

    public class Solution {
        public List<String> wordSubsets(String[] A, String[] B) {
            HashMap<Character, Integer> bMax = new HashMap<>();
            for (String  strB: B) {
                HashMap<Character, Integer> bMap = charCount(strB);
                for (Character cha : bMap.keySet()) {
                     bMax.put(cha, Math.max(bMax.getOrDefault(cha, 0), bMap.get(cha)));
                }
            }

            List<String> ans = new ArrayList<>();
            for (String strA: A) {
                HashMap<Character, Integer> aMap = charCount(strA);
                boolean flag = true;
                for (Character bKey: bMax.keySet()) {
                    if ((bMax.get(bKey) > aMap.getOrDefault(bKey,0))) {
                        flag = false;
                        break;
                    }
                }
                if (flag) ans.add(strA);
            }
            return ans;
        }

        public HashMap<Character, Integer> charCount ( String str) {
            var map = new HashMap<Character, Integer>();
            int count;
            //for (Character chA : strA.chars().mapToObj(c -> (char)c).toArray(Solution2Character[]::new) ) {
            for (int i = 0; i < str.length(); i++) {
                char chA = str.charAt(i);
                count = map.getOrDefault(chA,0) + 1;
                map.put(chA, count);
            }
            return map;
        }
    }