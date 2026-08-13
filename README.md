# SISTEMA DE MATRÍCULAS
Programa em C para gerenciamento de alunos via terminal.
Utiliza lista encadeada dinâmica com persistência em arquivo texto.

Desenvolvido como projeto prático da disciplina de Programação Avançada e Estrutura de Dados,
implementando as operações básicas de um CRUD completo.

---

## COMO USAR

Ao iniciar, o menu será exibido automaticamente.
Digite o número da opção e pressione Enter.

  1. Cadastrar aluno   — solicita matrícula e nome
  2. Listar alunos     — exibe todos os cadastrados
  3. Buscar aluno      — localiza pelo número de matrícula
  4. Atualizar aluno   — altera o nome de um aluno
  5. Remover aluno     — exclui permanentemente
  0. Sair              — encerra o programa

---

## FUNCIONAMENTO INTERNO

- Os dados são armazenados em uma lista encadeada alocada dinamicamente (malloc)
- Cada nó guarda os dados de um aluno e um ponteiro para o próximo nó
- Ao iniciar, o programa lê o arquivo alunos.txt e reconstrói a lista na memória
- O arquivo é atualizado automaticamente após cada cadastro, atualização ou remoção
- Matrículas são únicas — o sistema percorre a lista antes de cadastrar para impedir duplicatas
- A remoção usa dois ponteiros (atual e anterior) para desconectar o nó sem quebrar a lista,
  liberando a memória com free() em seguida

---

## ARQUIVO DE DADOS

Os dados são salvos em alunos.txt no formato:
  matricula; nome

Exemplo:
  2024001; Danilo Pereira
  
  2024002; Raimundo Amaral
  
  2024003; Lucas Antonelli

---

## OBSERVAÇÕES

- Não há limite de alunos (memória alocada dinamicamente conforme necessário)
- O nome aceita até 99 caracteres, incluindo espaços
- Se alunos.txt não existir ao iniciar, o programa começa com lista vazia sem erros
- Não é necessário sair para salvar — o arquivo é sempre atualizado após cada operação
