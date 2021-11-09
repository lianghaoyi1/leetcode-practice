class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.size()==0) return combinations;
        
        unordered_map<char,string> phonemap
        {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string combination;
        int index=0;
        backtrack(combinations,combination,index,digits,phonemap);
        return combinations;    
    }
    void backtrack(vector<string> &combinations,string &combination,int index,const string &digits,
        const unordered_map<char,string> &phonemap)
        {
            
            if(index==digits.size()) combinations.push_back(combination);
            else 
            {
                char digit=digits[index];
                const string letters=phonemap.at(digit);
                for(const char letter:letters)
                {
                    combination.push_back(letter);
                    backtrack(combinations,combination,index+1,digits,phonemap);
                    combination.pop_back();
                }

            }

        }
};
