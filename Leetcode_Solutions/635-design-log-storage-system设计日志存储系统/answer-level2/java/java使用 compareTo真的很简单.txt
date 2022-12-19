class LogSystem {
	LinkedList<Record> records = new LinkedList<LogSystem.Record>();
	
	class Record{
		static final String YEAR_STRING = "Year";
		static final String MONTH_STRING = "Month";
		static final String DAY_STRING = "Day";
		static final String HOUR_STRING = "Hour";
		static final String MINUTE_STRING = "Minute";
		static final String SECOND_STRING = "Second";
		
		int id;
		String timestamp;
		public Record(int id, String timestamp) {
			this.id = id;
			this.timestamp = timestamp;
		}
		
		public int compare(String timestamp, String string) {
			switch (string) {
			case YEAR_STRING:
				return this.timestamp.substring(0,4).compareToIgnoreCase(timestamp.substring(0,4));
			case MONTH_STRING:
				return this.timestamp.substring(0,7).compareToIgnoreCase(timestamp.substring(0,7));
			case DAY_STRING:
				return this.timestamp.substring(0, 10).compareToIgnoreCase(timestamp.substring(0, 10));
			case HOUR_STRING:
				return this.timestamp.substring(0, 13).compareToIgnoreCase(timestamp.substring(0, 13));
			case MINUTE_STRING:
				return this.timestamp.substring(0, 16).compareToIgnoreCase(timestamp.substring(0, 16));
			case SECOND_STRING:
				return this.timestamp.compareToIgnoreCase(timestamp);
			default:
				System.out.println("error");
				break;
			}
			
			return 0;
		}
		
	}
	
	
    public LogSystem() {
    	
    }
    
    public void put(int id, String timestamp) {
    	records.add(new Record(id, timestamp));
    }
    
    public List<Integer> retrieve(String s, String e, String gra) {
    	List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < records.size(); i++) {
			if(records.get(i).compare(s, gra) >= 0 && records.get(i).compare(e, gra) <= 0) {
				list.add(records.get(i).id);
			}
		}
        return list;
    }
}