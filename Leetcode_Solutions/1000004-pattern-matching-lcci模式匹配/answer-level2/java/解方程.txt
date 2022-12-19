有些边界的用例很奇怪了，特别是pattern或value为""的时候

```
    public boolean patternMatching(String pattern, String value) {
        if (pattern.length() == 0) {
            return value.length() == 0;
        }
        int sizeA = 0;
        int sizeB = 0;
        char[] pc = pattern.toCharArray();
        for (int i = 0; i < pc.length; i++) {
            if (pc[i] == 'a') {
                sizeA++;
            } else {
                sizeB++;
            }

        }
        //奇怪的用例???
        if (value.length() == 0) {
            return sizeA == 0 || sizeB == 0;
        }
        if (sizeA == 0) {
            return value.length() % sizeB == 0 && isValid(value, pc, 0, value.length() / sizeB);
        }
        if (sizeB == 0) {
            return value.length() % sizeA == 0 && isValid(value, pc, value.length() / sizeA, 0);
        }
        //长度可以是0,0就是""
        int maxLengthA = value.length() / sizeA;
        for (int i = 0; i <= maxLengthA; i++) {
            boolean canUse = (value.length() - sizeA * i) % sizeB == 0;
            if (!canUse) {
                continue;
            }
            int lb = (value.length() - sizeA * i) / sizeB;
            if (isValid(value, pc, i, lb)) {
                return true;
            }
        }
        return false;
    }

    private boolean isValid(String value, char[] p, int la, int lb) {
        String subA = null;
        String subB = null;
        int pointer = 0;
        for (int i = 0; i < p.length; i++) {
            boolean isA = p[i] == 'a';
            int le = isA ? la : lb;
            if (pointer + le > value.length()) {
                return false;
            }
            String v = value.substring(pointer, pointer + le);
            subA = isA && subA == null ? v : subA;
            subB = !isA && subB == null ? v : subB;
            if (Objects.equals(subA, subB)) {
                return false;
            }
            String sub = isA ? subA : subB;
            if (!v.equals(sub)) {
                return false;
            }
            pointer = pointer + le;
        }
        return true;
    }
```
