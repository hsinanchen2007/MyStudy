public String addBinary(String a, String b) {
    char[] aChars = a.toCharArray();
    char[] bChars = b.toCharArray();
    char[] bigChars = null;
    char[] smallChars = null;
    if (aChars.length < bChars.length) {
        bigChars = bChars;
        smallChars = aChars;
    } else {
        bigChars = aChars;
        smallChars = bChars;
    }
    char[] temp = new char[bigChars.length];
    for (int i = 0; i < temp.length; i++) {
        temp[i] = '0';
    }
    for (int i = smallChars.length - 1; i >= 0; i--) {
        temp[i + (bigChars.length - smallChars.length)] = smal
    }
    smallChars = temp;
    // 表示是否进一位
    boolean flag = false;
    for (int i = bigChars.length - 1; i >= 0; i--) {
        if (bigChars[i] + smallChars[i] == '1' + '1') {
            bigChars[i] = '0';
            if (flag == true) {
                // 在 1 + 1 的基础上还要再进一位，所以当前位为 1
                bigChars[i] = '1';
            }
            flag = true;
        } else {
            if (bigChars[i] + smallChars[i] > '0' + '0') {
                bigChars[i] = '1';
                if (flag == true) {
                    // 之前已经是 1 了，因为还要进一位，所以为 0
                    bigChars[i] = '0';
                    flag = true;
                }
            } else {
                bigChars[i] = '0';
                if (flag == true) {
                    bigChars[i] = '1';
                }
                flag = false;
            }
        }
    }
    if (flag == true) {
        temp = new char[bigChars.length + 1];
        for (int i = 1; i < temp.length; i++) {
            temp[i] = bigChars[i - 1];
        }
        temp[0] = '1';
        return new String(temp);
    }
    return new String(bigChars);
}