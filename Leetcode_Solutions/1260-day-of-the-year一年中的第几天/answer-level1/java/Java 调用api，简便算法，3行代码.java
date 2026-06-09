    import java.text.ParseException;
    import java.text.SimpleDateFormat;
    import java.util.Calendar;

    class Solution {
        public int dayOfYear(String date) {

            try {
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(new SimpleDateFormat("yyyy-MM-dd").parse(date));
                return calendar.get(Calendar.DAY_OF_YEAR);
            } catch (ParseException ignore) {}
            return 0;
        }
    }