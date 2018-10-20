# c_ransomware 
<h2>Sobre</h2>
<p>
  Ransomware é um malware que criptografa os arquivos armazenados em um dispositivo, e para que a vítiva possa obter novamente o acesso é exigido um pagamento.<br />
  O programa aplica essa função de criptografia de arquivos em um diretorio especifico, tendo em vista verificar seu funcionamento.
</p>
<h2>Funcionamento</h2>
<p>
Programa utiliza como base um sistema de cópia de arquivos, sendo que no processo de cópia é adicionado um método de codificação por byte.
</p>
<p>
  <b>Lógica</b><br />
  1. Abre o arquivo(in) em modo de leitura binaria<br />
  2. Abre outro arquivo(out) em modo de escrita binaria<br />
  3. Inicia a leitura dos Bytes do arquivo(in)<br />
  4. Cada Byte é modificado com base em uma Chave de codificação<br />
  5. Os Bytes modificados são inseridos no arquivo(out)<br />
  6. Por fim o arquivo(in) é removido
  
</p>
