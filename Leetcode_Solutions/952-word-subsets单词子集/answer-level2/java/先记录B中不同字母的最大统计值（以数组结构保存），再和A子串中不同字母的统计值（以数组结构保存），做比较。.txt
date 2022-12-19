```
    public List<String> wordSubSets(String[] A, String[] B) {

        LinkedList<String> result = new LinkedList<>();

        byte[] letterCountArr = new byte[26];
        for (String b : B) {

            //index at 0 is a(ch - 97)
            byte[] tmpLetterCountArr = stringToBits(b);

            for (int i = 0; i < tmpLetterCountArr.length; i++) {
                byte newLetterCnt = tmpLetterCountArr[i];
                if (newLetterCnt > 0) {
                    byte oldLetterCnt = letterCountArr[i];
                    if (oldLetterCnt == 0 || oldLetterCnt < newLetterCnt) {
                        letterCountArr[i] = newLetterCnt;
                    }
                }
            }
        }

        for (String a : A) {

            byte[] tmpLetterCountArr = stringToBits(a);

            boolean falg = true;
            for (int i = 0; i < letterCountArr.length; i++) {
                int tmp;
                if ((tmp = letterCountArr[i]) > 0 && tmp > tmpLetterCountArr[i]) {
                    falg = false;
                    break;
                }
            }

            if (falg) {
                result.add(a);
            }
        }

        return result;
    }

    /**
     * @param s
     * @return byte[] index is the s's ch-97
     */
    public byte[] stringToBits(String s) {
        char[] chars = s.toCharArray();

        byte[] arr = new byte[26];
        for (char ch : chars) {
            int i = ch - 97;
            arr[i]++;
        }
        return arr;
    }
```
