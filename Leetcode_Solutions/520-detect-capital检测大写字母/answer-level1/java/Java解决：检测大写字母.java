    public boolean detectCapitalUse(String word) {
        char[] array = word.toCharArray();

        if (array.length == 0 || array.length == 1) {
            return true;
        }

        if (array.length == 2 && Character.isLowerCase(array[0]) && Character.isUpperCase(array[1])) {
            return false;
        }

        if (array.length > 2) {
            if (Character.isUpperCase(array[0])) {
                if (Character.isUpperCase(array[1])) {
                    for (int i = 2; i < array.length; i ++) {
                        if (Character.isLowerCase(array[i])) {
                            return false;
                        }
                    }
                }
                if (Character.isLowerCase(array[1])) {
                    for (int i = 2; i < array.length; i ++) {
                        if (Character.isUpperCase(array[i])) {
                            return false;
                        }
                    }
                }
            }
            if (Character.isLowerCase(array[0])) {
                if (Character.isUpperCase(array[1])) {
                    return false;
                }
                if (Character.isLowerCase(array[1])) {
                    for (int i = 2; i < array.length; i ++) {
                        if (Character.isUpperCase(array[i])) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }