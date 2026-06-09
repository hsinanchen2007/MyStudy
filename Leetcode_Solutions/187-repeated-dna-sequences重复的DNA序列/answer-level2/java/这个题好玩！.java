    
    class Solution {
        public List<String> findRepeatedDnaSequences(String s) {
            List<String> list = new ArrayList<>();
            if(s.length() <= 10) {
                return list;
            }
            HashMap<Integer, Integer> hm = new HashMap<>();
            // 为A C G T这四个字母编码，只需要两位二进制即可，分别对应0 1 2 3，即00 01 10 11
            // 一个窗口里只有10个字母，10 * 2 = 20位二进制
            // 每次移动一个字母相当于左移两位
            int[] hash = new int[26];
            hash['A' - 'A'] = 0;
            hash['C' - 'A'] = 1;
            hash['G' - 'A'] = 2;
            hash['T' - 'A'] = 3;
            char[] c = s.toCharArray();
            int key = 0;
            for(int i = 0;i < 10;i++) {
                key = key << 2;
                key |= hash[c[i] - 'A'];
            }
            hm.put(key, 1);
            for(int i = 1;i + 9 < s.length();i++) {
                key = key << 2;
                key &= 0xfffff;     // mask的 4 * 5 = 20，低20位全是1，高12位全是0
                key |= hash[c[i + 9] - 'A'];
                if(hm.containsKey(key)) {
                    if(hm.get(key) == 1) {
                        list.add(s.substring(i, i + 10));
                    }
                    hm.put(key, hm.get(key) + 1);
                }else {
                    hm.put(key, 1);
                }
            }
            return list;
        }
    }