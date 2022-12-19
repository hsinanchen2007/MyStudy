```
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        enum class State
        {
            LOCAL,
            MET_PLUS,
            MET_AT,
        };
        
        set< string > unique_emails;
        for( const auto& email : emails ){
            string unique_email;
            unique_email.reserve( email.size() );
            auto state= State::LOCAL;
            for( auto c : email ){
                if( c == '@' ){
                    state= State::MET_AT;
                }else if( state == State::LOCAL ){
                    if( c == '.' ){
                        continue;
                    }else if( c == '+' ){
                        state= State::MET_PLUS;
                        continue;
                    }
                }else if( state == State::MET_PLUS ){
                    continue;
                }
                unique_email.push_back( c );
            }
            unique_emails.emplace( move( unique_email ) );
        }
        return unique_emails.size();
    }
};
```
