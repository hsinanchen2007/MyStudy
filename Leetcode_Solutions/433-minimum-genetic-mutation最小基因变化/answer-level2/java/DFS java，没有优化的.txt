```
int res = -1;

    /**
     * DFS
     *
     * @param start
     * @param end
     * @param bank
     * @return
     */
    public int minMutation(String start, String end, String[] bank) {
        Set<String> set = new HashSet<>();
        set.addAll(Arrays.asList(bank));
        helper(start, end, 0, set);
        return res;
    }

    private void helper(String start, String end, int mod, Set<String> bank) {
        if (start.equals(end)) {
            if (res == -1 || res > mod) {
                res = mod;
                return;
            }
            return;
        }
        if (mod >= bank.size()) {
            return;
        }
        char[] g = {'A', 'T', 'C', 'G'};
        for (int i = 0; i < start.length(); i++) {
            char[] array = start.toCharArray();
            for (char c : g) {
                if (array[i] == c) {
                    continue;
                }
                array[i] = c;

                if (!bank.contains(String.valueOf(array))) {
                    continue;
                }
                helper(String.valueOf(array), end, mod + 1, bank);
            }
        }

    }
```
