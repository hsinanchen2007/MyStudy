    public int[] prisonAfterNDays(int[] cells, int N) {
        String bits = Arrays.toString(cells).replaceAll(", ","")
                .replace("[","")
                .replace("]","");
        for(int i = 0;i < N;i ++) {
            System.out.println(bits);
            int value = Integer.parseInt(bits,2);
            value = ~(value^(value >>> 2));
            bits = Integer.toBinaryString(value);
            bits = bits.substring(bits.length() - 6);
            bits = '0' + bits + '0';
            if(i == 0) {
                N = (N - 1) % 14 + 1;
            }
        }
        for(int i = 0;i < cells.length;i ++) {
            cells[i] = bits.charAt(i) - '0';
        }
        return cells;
    }