public String removeDuplicates(String S) {

        String subRight = subString(S, 0, S.length() - 1);

        return subRight;
    }

    private String subString(String s, int start, int end) {

        if (start > end) {
            return "";
        }

        if (start == end) {
            return String.valueOf(s.charAt(start));
        }

        int mid = (start + end) / 2;
        String subLeft = subString(s, start, mid);
        String subRight = subString(s, mid + 1, end);

        return merge(subLeft, subRight);
    }

    private String merge(String subLeft, String subRight) {

        if (subLeft.length() <= 0) {
            return subRight;
        }

        if (subRight.length() <= 0) {
            return subLeft;
        }

        int subLeftIndex = subLeft.length() - 1;
        int subRightIndex = 0;

        StringBuffer buffer = new StringBuffer();
        while (subLeftIndex >= 0 && subRightIndex < subRight.length()) {
            if (subLeft.charAt(subLeftIndex) == subRight.charAt(subRightIndex)) {
                subLeftIndex--;
                subRightIndex++;
            } else {
                break;
            }
        }

        if (subLeftIndex >= 0) {
            buffer.append(subLeft.substring(0, subLeftIndex + 1));
        }

        if (subRightIndex < subRight.length()) {
            buffer.append(subRight.substring(subRightIndex, subRight.length()));
        }

        return buffer.toString();

    }