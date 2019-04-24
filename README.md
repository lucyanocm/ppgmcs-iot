# Central de Segurança de Baixo Custo
Projeto do programa de pós-graduação do mestrado em Modelagem Computacional de Sistemas da Universidade Federal do Tocantins, disciplina de
_IoT_ ministrado pelo [Profº Dr. Humberto Xavier de Araújo](http://buscatextual.cnpq.br/buscatextual/visualizacv.do?id=K4221833J6). 

Solução de baixo custo para auxílio na segurança pública e policia comunitária de Palmas-TO.

A  popularização  dos  microcontroladores  de  baixo custo tem permitido cada vez mais o desenvolvimento de soluções baseadas em 
Internt das coisas - _IoT_, a viabilidade financeira permite aplicar _IoT_ em soluções que o mercado ja tenha soluções comerciais,
porém com custo maior. Esta proposta de trabalho apresenta uma solução de baixo custo baseada no microcontrolador **Arduino UNO**,
para o problema de furtos residenciais no plano diretor da cidade de Palmas - TO, alinhados as políticas de segurança pública com 
base nas diretrizes de Policiamento Comunitário, facilitando a integração da comunidade e polícia militar, fornecendo informações
para viaturas de ́area no combate aos furtos. 

Sendo o objetivo  geral, fornecer informações para as guarnições da Polícia Militar de abertura de portas e janelas não autorizadas
em residências, sendo os objetivos específicos: 
* Desenvolve um algoritmo para sincronizar as ações entre os sensores e o envio do alerta
* Implementar um  dispositivo  para  fornecer  informações de aberturas não autorizadas
* Analisar  a  viabilidade  econômica  do  protótipo

## Materiais utilizados no projeto

- Arduíno UNO
  
![Arduíno UNO](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/arduinouno.jpg)
  
- Sensor de abertura MC-38A
  
![Sensor de abertura MC-38A](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/mc38a.jpg)

- Sensor de movimento HC-SR501
  
![Sensor de movimento HC-SR501](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/sensor_movimento.jpg)
  
- Shield GSM SIM800L
  
![Shield GSM SIM800L](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/sim800l.jpg)
  
- Regulador de tensão LM2596
  
![Regulador de tensão LM2596](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/regulador.jpg)
  
## Funcionamento do Algoritmo
  
A codificação foi feita utilizando a IDE [Arduíno](https://www.arduino.cc/), o arquivo com o código fonte está disponível nesse repositório: [project_ppgmcs_iot.ino](src/project_ppgmcs_iot.ino)
  
## Fluxograma do Sistema
  
![Fluxograma](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/fluxograma.jpeg)
  
## Esquema de montagem dos componentes
  
![Esquema de Montagem](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/projeto_iot_schema.png)
  
## Colaboradores do projeto

![Leonardo de Andrade Carneiro](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/leo_pb.jpg)

**[Leonardo de Andrade Carneiro](http://lattes.cnpq.br/5236550947764476)** - Possui graduação como Tecnólogo em Administração pela Universidade Norte do Paraná (2008),Especialização em Gestão Pública pelo Instituto Técnico de Marabá (2012) e Especialização em Docência Profissional e Tecnólogica pelo Instituto Federal de Educação, Ciência e Tecnologia do Tocantins (2012). Atualmente é sargento da Polícia Militar do Tocanitins atuando como auxiliar de Recursos Humanos  no primeiro batalhão de polícia militar.

![Lucyano Campos Martins](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/lucyano.jpg)

**[Lucyano Campos Martins](http://lattes.cnpq.br/3526769585643531)** - Aluno do programa de Mestrado Profissional em Modelagem Computacional de Sistemas da Universidade Federal do Tocantins, Especialista em Gestão da Tecnologia da Informação pela Faculdade Católica do Tocantins, Palmas-TO, conclusão 2010. Bacharel em Sistemas de Informação pelo Centro Universitário ITPAC (UNITPAC), Araguaína-TO, conclusão 2009. Técnico em Informática com ênfase em programação pela Escola Agrotécnica Federal de Inconfidentes-MG, conclusão 2003.

![Humberto Xavier de Araujo](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/humberto_pb.jpg)

**[Humberto Xavier de Araujo](http://lattes.cnpq.br/1914224370310328)** - Graduação em Engenharia de Telecomunicações, Mestrado em Engenharia Elétrica pela Universidade Federal do Pará UFPA (2007) e Doutorado e Pós doutorado em Engenharia Elétrica pela Universidade Estadual de Campinas - UNICAMP (2012). Tem experiência na área de Engenharia Elétrica com ênfase em Engenharia Eletrônica e Telecomunicações, atuando principalmente nos seguintes temas: comunicações móveis, micro-ondas, metamateriais, antenas planares e compatibilidade eletromagnética. Especialidade em microeletrônica, projetos de Circuitos Integrados Analógicos e de RF, e Antenas Inspiradas em Metamateriais. Atualmente é Professor Adjunto IV da Universidade Federal do Tocantins no curso de Engenharia Elétrica, e atua no programa de Mestrado em Modelagem Computacional de Sistemas na mesma instituição.

![Gentil Veloso Barbosa](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/gentil_pb.jpeg)

**[Gentil Veloso Barbosa](http://lattes.cnpq.br/4195102897973575)** - Possui graduação em Tecnologia em Processamento de Dados pela Universidade do Tocantins (1996), mestrado em Ciência da Computação pela Universidade Federal de Santa Catarina (2000) e Doutorado pela Universidade Federal do Rio de Janeiro (2015). Atualmente é professor Adjunto III da Fundação Universidade Federal do Tocantins e Diretor de Tecnologias Digitais. Tem experiência na área de Ciência da Computação, com ênfase em Teleinformática, atuando principalmente nos seguintes temas: Administração e Gerência de Redes, Educação e Tecnologias, Redes Complexas e Análise e Modelagem de Sistemas Computacionais.

![George Lauro Ribeiro de Brito](https://github.com/lucyanocm/ppgmcs-iot/blob/master/img/george.jpg)

**[George Lauro Ribeiro de Brito](http://lattes.cnpq.br/8779620606534106)** - Possui Graduação em Engenharia Elétrica pela Universidade Federal de Mato Grosso (2000), Especialização em Gestão Pública pela Universidade Federal do Tocantins (2013), Mestrado em Engenharia Elétrica pela Universidade de São Paulo (2003) e Doutorado em Engenharia Elétrica pela Universidade de Brasília (2009); é Professor Associado da Fundação Universidade Federal do Tocantins - UFT. Tem experiência na área de Engenharia Elétrica, com ênfase em Sistemas Elétricos de Potência.
