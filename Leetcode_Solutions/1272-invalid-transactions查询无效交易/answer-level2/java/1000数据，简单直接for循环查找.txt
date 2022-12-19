![image.png](https://pic.leetcode-cn.com/25de474925c80996c8e9839ddd42f9a367fc4448b4e44b80ff642031be921a48-image.png)

public static List<String> invalidTransactions(String[] transactions) {

        Trans[] trans = new Trans[transactions.length];

        int k = 0;
        for (String str : transactions) {
            String[] item = str.split(",");
            Trans tran = new Trans(item[0], Integer.parseInt(item[1]), Integer.parseInt(item[2]), item[3]);
            trans[k] = tran;
            k++;
        }

        List<String> result = new LinkedList<>();
        for (int i = 0; i < trans.length; i++) {
            if (trans[i].getAmount() > 1000) {
                StringBuffer sb = new StringBuffer();
                sb.append(trans[i].getName()).append(",").append(trans[i].getTime()).append(",").append(trans[i].getAmount()).append(",").append(trans[i].getCity());
                result.add(sb.toString());
                continue;
            }

            for (int j = 0; j < trans.length; j++) {
                if ((j != i) && (trans[i].getName().equals(trans[j].getName())) && !trans[i].getCity().equals(trans[j].getCity() ) && (Math.abs(trans[j].getTime() - trans[i].getTime()) <= 60)) {

                    StringBuffer sb = new StringBuffer();
                    sb.append(trans[i].getName()).append(",").append(trans[i].getTime()).append(",").append(trans[i].getAmount()).append(",").append(trans[i].getCity());
                    result.add(sb.toString());
                    break;
                }

            }
        }

        return result;
    }

    private static class Trans {
        private String name;
        private int time;
        private int amount;
        private String city;

        public String getName() {
            return name;
        }

        public int getTime() {
            return time;
        }

        public int getAmount() {
            return amount;
        }

        public String getCity() {
            return city;
        }

        public Trans(String name, int time, int amount, String city) {
            this.name = name;
            this.time = time;
            this.amount = amount;
            this.city = city;
        }
    }
