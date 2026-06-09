    public String defangIPaddr (String address) {

        char array[] = new char[address.length() + 6];

        for (int i = 0, j = 0; i < address.length() && j < address.length() + 6; i ++, j ++) {
            if (address.charAt(i) != '.') {
                array[j] = address.charAt(i);
            } else {
                array[j] = '[';
                j ++;
                array[j] = '.';
                j ++;
                array[j] = ']';
            }
        }

        address = String.valueOf(array);

        return address;
    }