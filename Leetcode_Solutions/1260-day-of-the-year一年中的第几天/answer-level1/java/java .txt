```
    int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int dayOfYear(String date) {
        String[] split = date.split("-");
        int year = Integer.valueOf(split[0]), month = Integer.valueOf(split[1]), day = Integer.valueOf(split[2]);
        int sum = day;
        for (int i = 0; i < month - 1; i++) {
            sum += days[i];
        }
        if (month > 2) {
            if (year % 4 == 0 && year % 100 != 0) {
                return sum + 1;
            } else if (year % 100 == 0 && year % 400 == 0) {
                return sum + 1;
            }
        }
        return sum;
    }
```
