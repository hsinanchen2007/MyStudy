
        try {
            if (x >= 0) {
                return Integer.parseInt(new StringBuilder().append(x).reverse().toString());
            } else {
                return -Integer.parseInt(new StringBuilder().append(-x).reverse().toString());
            }
        } catch (NumberFormatException e) {
            return 0;
        }