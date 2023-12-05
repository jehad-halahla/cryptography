#include <bits/stdc++.h>


using namespace std;

int main(){

    //we will use frequency analysis to break the cipher
    //chars will be only capital letters;
    string cipher_text = "IURPWKHULYHUWRWKHVHDSDOHVWLQHZLOOEHIUHH";
    vector<double>real_freq = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074}; //frequencies of each letter in the alphabet
    int key = 0; //key starts at 0
    int min_diff_key = -1; //we will store the key with the minimum difference
    //we will first try all different keys
    vector<string> texts;
    double min_diff = 10000;
    while(key <= 25){
        int freq[26] = {0};
        string plain_text = "";
        for(int i =0  ;i < cipher_text.size(); i++){
            freq[cipher_text[i] - 'A']++;
            int c = cipher_text[i] - 'A';
            c = (c - key + 26) % 26;//gets rid of negative numbers by adding 26
            plain_text += (c + 'A');
        }
        //we calc the sum 
        double sum = 0;
        for(int i = 0; i < 26; i++){
            sum += (real_freq[i]*(double)freq[(i+key)%26])/(cipher_text.size()*100.0);
            }
        texts.push_back(plain_text);
        if(abs(sum - 0.065) < min_diff){
            min_diff = abs(sum - 0.065);
            min_diff_key = key;
        }

        key++;
        
    }
    cout << "Key: " << min_diff_key << endl;
    cout << "Plain text: " << texts[min_diff_key] << endl;
    //we will print out the difference index 
    cout << "Difference index: " << min_diff << endl;
}