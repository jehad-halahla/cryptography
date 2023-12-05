#include <bits/stdc++.h>

using namespace std;

int main(){
   string  cypher_text = "JGRMQOYGHMVBJWRWQFPWHGFFDQGFPFZRKBEEBJIZQQOCIBZKLFAFGQVFZFWWEOGWOPFGFHWOLPHLRLOLFDMFGQWBLWBWQOLKFWBYLBLYLFSFLJGRMQBOLWJVFPFWQVHQWFFPQOQVFPQOCFPOGFWFJIGFQVHLHLROQVFGWJVFPFOLFHGQVQVFILEOGQILHQFQGIQVVOSFAFGBWQVHQWIJVWJVFPFWHGFIWIHZZRQGBABHZQOCGFHX";
   cout << cypher_text.size() << endl;
   vector<char>chars_sorted_by_freq = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'C', 'U', 'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'};
   map<char, int> freq;//to store actual frequencies
    for(int i = 0; i < cypher_text.size(); i++){
        freq[cypher_text[i]]++;
    }
    vector<pair<int, char>> sorted_freq; // to store sorted frequencies
    for(auto it = freq.begin(); it != freq.end(); it++){
        sorted_freq.push_back({it->second, it->first});//pushing the frequency and the char
    }
    sort(sorted_freq.begin(), sorted_freq.end());//sorts by frequency
    reverse(sorted_freq.begin(), sorted_freq.end());//to get max to min

    vector<pair<char, char>> mapping;
    for(int i = 0 ; i < sorted_freq.size(); i++){
        //cout << sorted_freq[i].second << " " << chars_sorted_by_freq[i] << endl;
        mapping.push_back({sorted_freq[i].second, chars_sorted_by_freq[i]});
    }
    string plain_text = "";
    for(int i = 0; i < cypher_text.size(); i++){
        for(int j = 0; j < mapping.size(); j++){
            if(cypher_text[i] == mapping[j].first){
                plain_text += mapping[j].second;
                break;
            }
           
        }
    }
    //we will print each character and its frequency
    for(int i = 0; i < sorted_freq.size(); i++){
        cout << sorted_freq[i].second << " " << sorted_freq[i].first << endl;
    }
    cout << plain_text << endl;

   

    return 0;
}